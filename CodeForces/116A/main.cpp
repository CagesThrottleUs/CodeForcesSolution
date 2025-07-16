/**
 * Sort your headers here
 */
#include <algorithm> // for std::max
#include <array>     // for std::array
#include <cstddef>   // for std::size_t
#include <cstdint>   // for std::uint8_t, std::int16_t, std::int32_t
#include <iostream>  // for std::cin, std::cout

/**
 * Template for fast I/O for competitive programming
 */
auto do_fast_io() -> void
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

// Your functions and other stuff here

/**
 * The namespace that would contain the solution to the problem piece by piece
 */
namespace Solution
{

/**
 * @brief possible error codes that can come up for the program
 */
enum ERROR_CODES : std::uint8_t
{
    SUCCESS = 0,
    INPUT_STREAM_ERROR = 2
};

constexpr std::int16_t MIN_TEST_CASES{2};
constexpr std::int16_t MAX_TEST_CASES{1000};

constexpr std::int16_t MIN_PEOPLE{0};
constexpr std::int16_t MAX_PEOPLE{1000};

constexpr std::array<ERROR_CODES, 4> ERROR_LOOKUP = {
    ERROR_CODES::SUCCESS,            // state 0: normal state
    ERROR_CODES::SUCCESS,            // state 1: eof only
    ERROR_CODES::INPUT_STREAM_ERROR, // state 2: fail only
    ERROR_CODES::INPUT_STREAM_ERROR  // state 3: eof + fail
};

/**
 * @brief the input parameters for the program
 */
struct TotalTestCases
{
    std::int16_t value;
    ERROR_CODES error_code;

    [[nodiscard]] constexpr auto is_valid() const noexcept -> bool
    {
        return error_code == ERROR_CODES::SUCCESS && MIN_TEST_CASES <= value && value <= MAX_TEST_CASES;
    }
};

/**
 * @brief read the input from the standard input stream
 * @return the input parameters
 */
[[nodiscard]] inline auto read_total_test_cases() noexcept -> TotalTestCases
{
    std::int16_t value{};
    const bool read_success = static_cast<bool>(std::cin >> value);

    const std::size_t state_index = (std::cin.eof() ? 1 : 0) + (std::cin.fail() ? 2 : 0);

    const ERROR_CODES error_code =
        read_success ? ERROR_CODES::SUCCESS
                     : ERROR_LOOKUP[state_index]; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)

    return TotalTestCases{.value = value, .error_code = error_code};
}

/**
 * @brief the input parameters for the program
 */
struct TrainStation
{
    std::int16_t enter;
    std::int16_t exit;
    ERROR_CODES error_code;

    [[nodiscard]] constexpr auto is_valid() const noexcept -> bool
    {
        return error_code == ERROR_CODES::SUCCESS && (MIN_PEOPLE <= enter && enter <= MAX_PEOPLE) &&
               (MIN_PEOPLE <= exit && exit <= MAX_PEOPLE);
    }
};

/**
 * @brief read the input from the standard input stream
 * @return the input parameters
 */
[[nodiscard]] inline auto read_train_station() noexcept -> TrainStation
{
    std::int16_t enter{};
    std::int16_t exit{};

    const bool read_success = static_cast<bool>(std::cin >> exit >> enter); // First input is exit, then enter

    const std::size_t state_index = (std::cin.eof() ? 1 : 0) + (std::cin.fail() ? 2 : 0);

    const ERROR_CODES error_code =
        read_success ? ERROR_CODES::SUCCESS
                     : ERROR_LOOKUP[state_index]; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)

    return TrainStation{.enter = enter, .exit = exit, .error_code = error_code};
}

/**
 * @brief compute the size of the train
 * @param current_size the current size of the train
 * @param train_station the train station
 * @param max_size the maximum size of the train
 * @return the updated max size of the train
 */
inline auto compute_size(std::int32_t &current_size, const TrainStation &train_station, std::int32_t &max_size) noexcept
    -> void
{
    current_size -= static_cast<std::int32_t>(train_station.exit);
    max_size = std::max(max_size, current_size);
    current_size += static_cast<std::int32_t>(train_station.enter);
    max_size = std::max(max_size, current_size);
}

/**
 * @brief solve the problem
 */
inline auto solve() noexcept -> void
{
    TotalTestCases total_test_cases{read_total_test_cases()};
    if (total_test_cases.is_valid())
    {
        std::int32_t max_size{0};
        std::int32_t current_size{0};
        for (std::int16_t i{0}; i < total_test_cases.value; ++i)
        {
            TrainStation train_station{read_train_station()};
            if (train_station.is_valid())
            {
                compute_size(current_size, train_station, max_size);
            }
        }
        std::cout << max_size << '\n';
    }
}

} // namespace Solution

/**
 * Main function
 */
auto main() noexcept -> int
{
    // Fast I/O for competitive programming
    do_fast_io();

    // Your code here
    Solution::solve();

    return 0;
}

/**
 * Sort your headers here
 */
#include <array>    // for std::array
#include <cstddef>  // for std::size_t
#include <cstdint>  // for std::uint8_t, std::int64_t
#include <iostream> // for std::cin, std::cout

/**
 * Template for fast I/O for competitive programming
 */
inline auto do_fast_io() noexcept -> void
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

/**
 * The namespace that would contain the solution to the problem piece by piece
 */
namespace Solution
{

// Compile-time constants for optimal performance
constexpr std::int64_t LUCKY_DIGIT_4{4};
constexpr std::int64_t LUCKY_DIGIT_7{7};
constexpr std::int64_t BASE_10{10};

/**
 * @brief possible error codes that can come up for the program
 */
enum ERROR_CODES : std::uint8_t
{
    SUCCESS = 0,
    INVALID_INPUT = 1,
    INPUT_STREAM_ERROR = 2
};

/**
 * @brief the input parameters for the program
 */
struct InputParams
{
    std::int64_t value;     // Most frequently accessed first
    ERROR_CODES error_code; // Smaller type second for optimal packing

    [[nodiscard]] constexpr auto is_valid() const noexcept -> bool
    {
        return error_code == ERROR_CODES::SUCCESS;
    }
};

/**
 * @brief read the input from the standard input stream
 * @return the input parameters
 */
auto read_input() noexcept -> InputParams
{
    std::int64_t value{};
    const bool read_success = static_cast<bool>(std::cin >> value);

    // Exception-safe: state_index is guaranteed to be in range [0,3]
    const std::size_t state_index = (std::cin.eof() ? 1 : 0) + (std::cin.fail() ? 2 : 0);

    // Constexpr lookup table in read-only memory for cache efficiency
    static constexpr std::array<ERROR_CODES, 4> error_lookup = {
        ERROR_CODES::SUCCESS,            // state 0: normal state
        ERROR_CODES::SUCCESS,            // state 1: eof only
        ERROR_CODES::INPUT_STREAM_ERROR, // state 2: fail only
        ERROR_CODES::INPUT_STREAM_ERROR  // state 3: eof + fail
    };

    // Use [] operator instead of at() - no exception, bounds guaranteed by logic
    const ERROR_CODES error_code =
        read_success ? ERROR_CODES::SUCCESS
                     : error_lookup[state_index]; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)

    return InputParams{.value = value, .error_code = error_code};
}

/**
 * @brief count the lucky digits in the value
 * @param value the value to count the lucky digits in
 * @return the number of lucky digits in the value
 */
auto count_lucky_digits(std::int64_t value) noexcept -> std::uint8_t
{
    std::uint8_t count{0};
    while (value > 0)
    {
        if (value % BASE_10 == LUCKY_DIGIT_4 || value % BASE_10 == LUCKY_DIGIT_7)
        {
            count++;
        }
        value /= BASE_10;
    }
    return count;
}

/**
 * @brief solve the problem
 */
inline auto solve() noexcept -> void
{
    InputParams input{read_input()};
    std::uint8_t lucky_cnt{0};
    if (input.is_valid())
    {
        lucky_cnt = count_lucky_digits(input.value);
    }
    std::cout << ((lucky_cnt == LUCKY_DIGIT_4 || lucky_cnt == LUCKY_DIGIT_7) ? "YES" : "NO") << '\n';
}

} // namespace Solution

/**
 * Main function
 */
auto main() noexcept -> int
{
    // Fast I/O setup
    do_fast_io();

    // Your code here
    Solution::solve();

    return 0;
}

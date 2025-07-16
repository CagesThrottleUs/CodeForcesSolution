/**
 * Sort your headers here
 */
#include <array>     // for std::array
#include <cstddef>   // for std::size_t
#include <cstdint>   // for std::uint8_t
#include <iostream>  // for std::cin, std::cout
#include <stdexcept> // for std::runtime_error
#include <string>    // for std::to_string
#include <utility>   // for std::cmp_less

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

constexpr int MIN_TOTAL_KIDS = 1;
constexpr int MAX_TOTAL_KIDS = 100;

/**
 * @brief The error codes that can be returned by the solution
 */
enum class ErrorCode : std::uint8_t
{
    SUCCESS = 0,
    INVALID_INPUT = 1,
    INPUT_READ_FAILED = 2,
    PROCESSING_FAILED = 3
};

/**
 * @brief The input parameters for the solution
 */
struct InputParams
{
    ErrorCode error_code;
    int value;

    InputParams(ErrorCode error_code, int value) : error_code(error_code), value(value)
    {
    }

    [[nodiscard]] auto is_valid() const -> bool
    {
        return error_code == ErrorCode::SUCCESS && value >= MIN_TOTAL_KIDS && value <= MAX_TOTAL_KIDS;
    }
};

/**
 * @brief The output parameters for the solution
 */
struct OutputParams
{
    ErrorCode error_code;
    std::array<int, MAX_TOTAL_KIDS> value;

    OutputParams(ErrorCode error_code, std::array<int, MAX_TOTAL_KIDS> value) : error_code(error_code), value(value)
    {
    }

    [[nodiscard]] auto is_valid() const -> bool
    {
        return error_code == ErrorCode::SUCCESS;
    }
};

/**
 * @brief Read input from input stream
 * @note the first kid is the total number of children after which it would be the receiver of the gift
 */
auto read_input() -> InputParams
{
    int total_kids{};
    if (!(std::cin >> total_kids))
    {
        return InputParams{ErrorCode::INPUT_READ_FAILED, 0};
    }
    if (total_kids < MIN_TOTAL_KIDS || total_kids > MAX_TOTAL_KIDS)
    {
        return InputParams{ErrorCode::INVALID_INPUT, 0};
    }
    return InputParams{ErrorCode::SUCCESS, total_kids};
}

/**
 * @brief Generate a vector that describes which kid gives a gift to which kid
 * @param total_kids the number of kids
 * @return the vector
 */
auto generate_vector(int total_kids) -> OutputParams
{
    OutputParams result{ErrorCode::SUCCESS, {}};
    for (int i = 0; i < total_kids; ++i)
    {
        InputParams kid_receiver{read_input()};
        if (kid_receiver.is_valid())
        {
            std::size_t index{static_cast<std::size_t>(kid_receiver.value) - 1};
            result.value[index] = i + 1; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
        }
        else
        {
            result.error_code = ErrorCode::PROCESSING_FAILED;
            break;
        }
    }
    return result;
}

/**
 * @brief Print the vector
 * @param arr the vector to print
 * @param total_kids the number of kids
 */
auto print_vector(const std::array<int, MAX_TOTAL_KIDS> &arr, int total_kids) -> void
{
    std::size_t max_idx{static_cast<std::size_t>(total_kids) - 1};
    for (std::size_t i = 0; i <= max_idx; ++i)
    {
        if (i != 0)
        {
            std::cout << " ";
        }
        std::cout << arr.at(i);
    }
    std::cout << '\n';
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

    Solution::InputParams params{Solution::read_input()};
    if (!params.is_valid())
    {
        std::cerr << "Invalid input parameters" << '\n';
        return 1;
    }
    Solution::OutputParams output{Solution::generate_vector(params.value)};
    if (!output.is_valid())
    {
        std::cerr << "Processing failed" << '\n';
        return 1;
    }
    Solution::print_vector(output.value, params.value);
    return 0;
}

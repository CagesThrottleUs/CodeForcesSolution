/**
 * Sort your headers here
 */
#include <algorithm> // for std::count_if
#include <cstdint>   // for std::uint16_t, std::uint8_t
#include <iostream>  // for I/O operations
#include <vector>    // for std::vector

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

namespace Solution
{

constexpr std::uint32_t MAX_NUMBER{10000};
constexpr std::uint32_t MIN_NUMBER{1};
constexpr std::uint8_t BASE{10};

namespace Details
{
/**
 * Read input for a single test case
 * @param number Reference to the number to read
 * @return true if input is valid, false otherwise
 */
auto read_input(std::uint16_t &number) -> bool
{
    if (!(std::cin >> number))
    {
        return false;
    }
    return (number >= MIN_NUMBER && number <= MAX_NUMBER);
}

/**
 * Express a number in base 10
 * @param number The number to express
 * @return A vector of digits in base 10
 */
auto express_num_in_base_10(std::uint16_t number) -> std::vector<std::uint8_t>
{
    std::vector<std::uint8_t> result;
    while (number > 0)
    {
        result.push_back(number % BASE);
        number /= BASE;
    }
    return result;
}

/**
 * Count the number of non-zero digits
 * @param digits The vector of digits
 * @return The number of non-zero digits
 */
auto print_count_of_non_zero_digits(const std::vector<std::uint8_t> &digits) -> void
{
    std::cout << std::count_if(digits.begin(), digits.end(), [](std::uint8_t digit) { return digit != 0; }) << '\n';
}

auto print_digits(const std::vector<std::uint8_t> &digits) -> void
{
    int multiplier{1};
    bool is_first{true};
    for (std::size_t i{0}; i < digits.size(); ++i)
    {
        const auto digit{digits[i]};
        // std::cout << "digit: " << static_cast<int>(digit) << '\n';
        // std::cout << "is begin: " << (it == digits.begin()) << '\n';
        if (is_first && digit != 0)
        {
            std::cout << digit * multiplier;
            is_first = false;
        }
        else if (digit != 0)
        {
            std::cout << ' ' << digit * multiplier;
        }
        multiplier *= BASE;
    }
    std::cout << '\n';
}
} // namespace Details

/**
 * Solve the problem
 * @return void
 */
auto solve() -> void
{
    std::uint16_t test_cases{};
    std::cin >> test_cases;
    for (std::uint16_t i{0}; i < test_cases; ++i)
    {
        std::uint16_t number{};
        if (!Details::read_input(number))
        {
            std::cerr << "Error: Invalid input expected number between " << MIN_NUMBER << " and " << MAX_NUMBER << '\n';
            return;
        }

        const auto digits{Details::express_num_in_base_10(number)};
        Details::print_count_of_non_zero_digits(digits);
        Details::print_digits(digits);
    }
}

} // namespace Solution

/**
 * Main function
 */
auto main() -> int
{
    // Fast I/O for competitive programming
    do_fast_io();

    // Your code here
    Solution::solve();

    return 0;
}

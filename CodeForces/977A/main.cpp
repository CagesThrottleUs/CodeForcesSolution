/**
 * Sort your headers here
 */

#include <cstdint>  // for std::uint8_t
#include <iostream> // for std::cin, std::cout

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

constexpr auto BASE_10 = 10;

enum class PROGRAM_MODE : std::uint8_t
{
    SOLVE = 0,
    // TEST = 1,
    DEBUG = 2,
};

constexpr auto CURRENT_PROGRAM_MODE = PROGRAM_MODE::SOLVE;

/**
 * Input struct for the solution
 */
struct Input
{
    std::uint32_t n;
    std::uint8_t k;

    auto operate() noexcept -> std::int32_t
    {
        auto result = static_cast<std::int32_t>(n);
        if (CURRENT_PROGRAM_MODE == PROGRAM_MODE::DEBUG)
        {
            std::cout << "START STATE: n=" << n << ", k=" << static_cast<std::int32_t>(k) << '\n';
        }
        while (k > static_cast<std::uint8_t>(0))
        {
            if (result % BASE_10 == 0)
            {
                result /= BASE_10;
            }
            else
            {
                result--;
            }
            k--;
            if (CURRENT_PROGRAM_MODE == PROGRAM_MODE::DEBUG)
            {
                std::cout << "AFTER OPERATION: n=" << result << ", k=" << static_cast<std::int32_t>(k) << '\n';
                std::cout << "CONDITION for k: " << (k > static_cast<std::uint8_t>(0)) << '\n';
            }
        }
        return result;
    }
};

auto read_input() -> Input
{
    std::uint32_t input_n{};
    std::int32_t input_k{};
    std::cin >> input_n >> input_k;
    return Input{.n = input_n, .k = static_cast<std::uint8_t>(input_k)};
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
    std::cout << Solution::read_input().operate() << '\n';

    return 0;
}

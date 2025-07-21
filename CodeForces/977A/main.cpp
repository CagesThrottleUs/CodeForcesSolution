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
constexpr auto ENABLE_DEBUG = (CURRENT_PROGRAM_MODE == PROGRAM_MODE::DEBUG);

template <typename T> constexpr auto debug_log(T &&message) noexcept -> void
{
    if constexpr (ENABLE_DEBUG)
    {
        std::cout << std::forward<T>(message) << '\n';
    }
}

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
        debug_log("START STATE: n=" + std::to_string(n) + ", k=" + std::to_string(static_cast<std::int32_t>(k)));
        while (k > 0U)
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
            debug_log("AFTER OPERATION: n=" + std::to_string(result) +
                      ", k=" + std::to_string(static_cast<std::int32_t>(k)));
            // debug_log("CONDITION for k: " + std::to_string(k > static_cast<std::uint8_t>(0)));
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

/**
 * Sort your headers here
 */
#include <algorithm> // for std::maz
#include <cstdint>   // for std::int64_t, std::uint32_t
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

constexpr auto DEBUG_MODE{false};

template <typename T> constexpr auto debug(const T &value) noexcept -> void
{
    if constexpr (DEBUG_MODE)
    {
        std::cout << value << '\n';
    }
}

/**
 * Input struct
 */
struct Input
{
    std::uint32_t dollars_per_item;
    std::uint32_t total_items;
    std::uint32_t dollars_available;
};

/**
 * Output struct
 */
struct Output
{
    std::uint32_t dollars_needed;
};

/**
 * Read input from stdin
 */
auto read_input() -> Input
{
    std::uint32_t dollars_per_item{};
    std::uint32_t total_items{};
    std::uint32_t dollars_available{};

    std::cin >> dollars_per_item >> dollars_available >> total_items;

    return Input{
        .dollars_per_item = dollars_per_item,
        .total_items = total_items,
        .dollars_available = dollars_available,
    };
}

/**
 * Solve the problem
 */
auto solve(const Input &input) -> Output
{
    std::int64_t dollars_needed{static_cast<std::int64_t>(input.total_items) * (input.total_items + 1)};

    debug(dollars_needed);

    dollars_needed *= input.dollars_per_item;

    debug(dollars_needed);

    dollars_needed /= 2;

    debug(dollars_needed);

    dollars_needed =
        std::max(dollars_needed - static_cast<std::int64_t>(input.dollars_available), static_cast<std::int64_t>(0));

    return Output{static_cast<std::uint32_t>(dollars_needed)};
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
    const auto input = Solution::read_input();
    const auto output = Solution::solve(input);
    std::cout << output.dollars_needed << '\n';

    return 0;
}

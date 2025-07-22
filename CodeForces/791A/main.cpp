/**
 * Sort your headers here
 */
#include <cmath>    // for std::log2, std::floor
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

constexpr auto DEBUG_MODE{false};

template <typename T> constexpr auto debug(const T &value) noexcept -> void
{
    if constexpr (DEBUG_MODE)
    {
        std::cout << value << '\n';
    }
}

const double DIFF_LOG_3_AND_2{std::log2(3) - std::log2(2)}; // log2(3) - log2(2)

void solve() noexcept
{
    int weight_limak{};
    int weight_bob{};

    std::cin >> weight_limak >> weight_bob;

    debug(weight_limak);
    debug(weight_bob);

    const auto log_limak = std::log2(weight_limak);
    const auto log_bob = std::log2(weight_bob);

    const auto diff_log = log_bob - log_limak;

    debug(log_limak);
    debug(log_bob);
    debug(diff_log);
    debug(DIFF_LOG_3_AND_2);

    const auto divide = diff_log / DIFF_LOG_3_AND_2;
    const auto floor_divide = std::floor(divide);

    debug(divide);
    debug(floor_divide);

    const auto years = std::floor(divide) + 1;

    debug(years);

    std::cout << years << '\n';
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

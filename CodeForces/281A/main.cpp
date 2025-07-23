/**
 * Sort your headers here
 */
#include <array>    // for std::array (stack-based)
#include <cctype>   // for std::toupper
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

enum class SolveResult : std::uint8_t
{
    SUCCESS = 0,
    INPUT_ERROR = 1,
    PROCESSING_ERROR = 2
};

constexpr std::size_t MAX_WORD_SIZE{1001};

[[nodiscard]] auto solve() noexcept -> SolveResult
{
    std::array<char, MAX_WORD_SIZE> word{};

    if (!std::cin.getline(word.data(), MAX_WORD_SIZE))
    {
        return SolveResult::INPUT_ERROR;
    }

    word[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(word[0])));

    std::cout << word.data() << '\n';

    return SolveResult::SUCCESS;
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
    const auto result = Solution::solve();

    return static_cast<int>(result);
}

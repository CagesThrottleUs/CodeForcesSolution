/**
 * Sort your headers here
 */
#include <array>    // for std::array (stack-based)
#include <bitset>   // for std::bitset
#include <cstddef>  // for std::size_t
#include <cstdint>  // for std::uint8_t
#include <cstring>  // for C-style string operations
#include <iostream> // for std::cin, std::cout
#include <string>   // for std::string, std::string_view

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

constexpr std::string_view CHAT_WITH_HER{"CHAT WITH HER!"};
constexpr std::string_view IGNORE_HIM{"IGNORE HIM!"};
constexpr std::size_t MAX_USERNAME_SIZE = 100;
constexpr std::size_t TOTAL_ASCII_CHARACTERS = 256;

/**
 * HFT-style error codes for deterministic behavior
 */
enum class SolveResult : std::uint8_t
{
    SUCCESS = 0,
    INPUT_ERROR = 1,
    PROCESSING_ERROR = 2
};

/**
 * Solve the problem here - HFT style with zero dynamic allocation
 */
[[nodiscard]] auto solve() noexcept -> SolveResult
{
    // Stack-based buffer - no dynamic allocation
    std::array<char, MAX_USERNAME_SIZE + 1> username_buffer{};

    // Use C-style input for deterministic performance
    if (!std::cin.getline(username_buffer.data(), MAX_USERNAME_SIZE))
    {
        return SolveResult::INPUT_ERROR;
    }

    // Stack-based unique character tracking (ASCII only)
    std::bitset<TOTAL_ASCII_CHARACTERS> char_seen{}; // All ASCII characters
    size_t unique_count = 0;

    // Process characters without exceptions or dynamic allocation
    for (const auto ascii_ch : username_buffer)
    {
        if (ascii_ch == '\0')
        {
            break;
        }

        const auto ascii_ch_index = static_cast<unsigned char>(ascii_ch);

        if (!char_seen[ascii_ch_index]) // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index) (we know that the
                                        // index is valid)
        {
            char_seen[ascii_ch_index] = true; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index) (we know that
                                              // the index is valid)
            ++unique_count;
        }
    }

    // Deterministic output without string creation
    if (unique_count % 2 == 0)
    {
        // Direct C-string output - no string object creation
        std::cout.write(CHAT_WITH_HER.data(), CHAT_WITH_HER.size());
    }
    else
    {
        std::cout.write(IGNORE_HIM.data(), IGNORE_HIM.size());
    }
    std::cout.put('\n');

    return SolveResult::SUCCESS;
}
} // namespace Solution

/**
 * Main function - HFT style with error code handling
 */
auto main() noexcept -> int
{
    // Fast I/O for competitive programming
    do_fast_io();

    // Execute with deterministic error handling
    const auto result = Solution::solve();

    // Return appropriate exit code for monitoring systems
    return static_cast<int>(result);
}

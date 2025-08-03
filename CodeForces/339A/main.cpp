/**
 * Sort your headers here
 */
#include <algorithm> // for std::swap
#include <cstddef>   // for std::size_t
#include <cstdint>   // for std::uint8_t
#include <iostream>  // for std::cin, std::cout
#include <string>    // for std::string

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

constexpr auto SUCCESS = 0;
constexpr auto ERROR_READING_INPUT = 1;
constexpr auto BAD_ALLOCATION = 2;
constexpr auto UNKNOWN_ERROR = 3;

constexpr auto MAX_INPUT_LENGTH = 100;

constexpr auto SKIP_LENGTH = 2;

constexpr auto DEBUG_MODE = false;
// constexpr auto SKIP_CHAR = '+';

/**
 * Debug print function
 */
template <typename T> auto debug_print(const T &value) -> void
{
    if constexpr (DEBUG_MODE)
    {
        std::cout << value << '\n';
    }
}

/**
 * Compare and swap function
 */
auto compare_and_swap(std::string &input, int &start, std::size_t &curr, int &end) -> void
{
    const char curr_char = input[curr];

    debug_print("curr_char: " + std::string(1, curr_char));

    if (curr_char == '1')
    {
        start += 1 + (start >= 0);
        std::swap(input[static_cast<std::size_t>(start)], input[curr]);
        curr += SKIP_LENGTH;
    }
    else if (curr_char == '3')
    {
        end -= 1 + (static_cast<std::size_t>(end) < input.size());
        std::swap(input[curr], input[static_cast<std::size_t>(end)]);
    } else {
        curr += SKIP_LENGTH;
    }
}

/**
 * Read the input and return the Counter object
 */
auto solve() -> void
{
    std::string input;
    input.reserve(MAX_INPUT_LENGTH);
    std::cin >> input;

    debug_print("Input: " + input);

    int start{-1};
    int end{static_cast<int>(input.size())};

    std::size_t curr{0};

    while (start < static_cast<int>(curr) and curr < static_cast<std::size_t>(end))
    {
        debug_print("--------------------------------");
        debug_print("curr: " + std::to_string(curr));
        debug_print("start: " + std::to_string(start));
        debug_print("end: " + std::to_string(end));

        compare_and_swap(input, start, curr, end);

        debug_print("--------------------------------");
    }

    std::cout << input << '\n';
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
    try
    {
        Solution::solve();
        return Solution::SUCCESS;
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return Solution::BAD_ALLOCATION;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return Solution::ERROR_READING_INPUT;
    }
    catch (...)
    {
        std::cerr << "Unknown error\n";
        return Solution::UNKNOWN_ERROR;
    }
}

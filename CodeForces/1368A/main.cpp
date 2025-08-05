/**
 * Sort your headers here
 */
#include <algorithm> // for std::min, std::max
#include <cstdint>   // for std::uint32_t
#include <iostream>  // for std::cin, std::cout
#include <stdexcept> // for std::runtime_error
#include <utility>   // for std::swap

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

constexpr auto BAD_ALLOC_EXIT_CODE = 1;
constexpr auto UNKNOWN_EXCEPTION_EXIT_CODE = 2;
constexpr auto SUCCESS_EXIT_CODE = 0;

constexpr auto MAX_INPUT_VALUE = 1'000'000'000;
constexpr auto MIN_INPUT_VALUE = 1;

/**
 * A structure that represents a test case.
 *
 * First field is the smaller input and is guaranteed to be the smallest number.
 * Second field is the larger input and is guaranteed to be the largest number.
 * Third field is the target number which we have to exceed.
 */
struct TestCase
{
    std::uint32_t smallest;
    std::uint32_t largest;
    std::uint32_t target;

    auto guarantee_order() -> void
    {
        auto smaller = std::min(smallest, largest);
        auto larger = std::max(smallest, largest);

        smallest = smaller;
        largest = larger;
    }
};

/**
 * Read a single test case.
 */
auto read_test_case() -> TestCase
{
    std::uint32_t smallest{};
    std::uint32_t largest{};
    std::uint32_t target{};

    if (!(std::cin >> smallest >> largest >> target))
    {
        throw std::runtime_error("Failed to read input");
    }

    if (smallest < MIN_INPUT_VALUE || smallest > MAX_INPUT_VALUE || largest < MIN_INPUT_VALUE ||
        largest > MAX_INPUT_VALUE || target < MIN_INPUT_VALUE || target > MAX_INPUT_VALUE)
    {
        throw std::runtime_error("Input out of range");
    }

    TestCase test_case{.smallest = smallest, .largest = largest, .target = target}; // Guaranteed to be in [1, 10^9]
    test_case.guarantee_order();

    return test_case;
}

/**
 * Read the input for the test cases.
 *
 * The input is a number of test cases followed by the test cases themselves.
 * Each test case is a line with three numbers: a, b, and n.
 *
 * The output is the number of operations needed to make the target number greater than or equal to n.
 *
 */
auto solve() -> void
{
    std::uint32_t num_test_cases{};
    std::cin >> num_test_cases;

    for (std::uint32_t i = 0; i < num_test_cases; ++i)
    {
        auto test_case = read_test_case();

        std::uint32_t operations = 0;

        while (test_case.smallest <= test_case.target && test_case.largest <= test_case.target)
        {
            test_case.smallest += test_case.largest; // Guaranteed to never exceed the target
            operations++;
            test_case.guarantee_order();
        }

        std::cout << operations << '\n';
    }
}
} // namespace Solution

/**
 * Main function
 */
auto main() noexcept -> int
{
    // Fast I/O for competitive programming
    do_fast_io();

    try
    {
        Solution::solve();
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << e.what() << '\n';
        return Solution::BAD_ALLOC_EXIT_CODE;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return Solution::UNKNOWN_EXCEPTION_EXIT_CODE;
    }
    catch (...)
    {
        std::cerr << "Unknown exception occurred\n";
        return Solution::UNKNOWN_EXCEPTION_EXIT_CODE;
    }

    return Solution::SUCCESS_EXIT_CODE;
}

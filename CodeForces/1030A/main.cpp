/**
 * Sort your headers here
 */
#include <iostream>  // for std::cin, std::cout
#include <stdexcept> // for std::runtime_error
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
static constexpr int MIN_TOTAL_CASES = 1;   // minimum number of test cases in the problem statement
static constexpr int MAX_TOTAL_CASES = 100; // maximum number of test cases in the problem statement

/**
 * Solves the problem
 */
auto solve() -> std::string
{
    int total_test_cases{};
    if (!(std::cin >> total_test_cases))
    {
        throw std::runtime_error("Failed to read input");
    }
    if (total_test_cases < MIN_TOTAL_CASES || total_test_cases > MAX_TOTAL_CASES)
    {
        throw std::runtime_error("Invalid total test cases must be between " + std::to_string(MIN_TOTAL_CASES) +
                                 " and " + std::to_string(MAX_TOTAL_CASES));
    }

    std::string decision{"EASY"};

    for (int i = 0; i < total_test_cases; ++i)
    {
        int test_case{};
        if (!(std::cin >> test_case))
        {
            throw std::runtime_error("Failed to read input");
        }

        if (test_case == 1)
        {
            decision = "HARD";
        }
    }

    return decision;
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
    try
    {
        std::cout << Solution::solve() << '\n';
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown error occurred\n";
        return 1;
    }

    return 0;
}

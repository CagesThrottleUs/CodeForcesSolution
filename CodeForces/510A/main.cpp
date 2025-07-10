/**
 * Sort your headers here
 */
#include <iostream>
#include <string>

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

constexpr int MAX_PARAMS_VALUE = 50;
constexpr int MIN_PARAMS_VALUE = 3;
constexpr int DIVISOR_FOR_EVEN_LINES = 4;

/**
 * The struct that would contain the input parameters n, m
 */
struct InputParams
{
    int n; // number of lines, always odd
    int m; // number of characters in each line

    /**
     * Check if the input parameters are valid
     * @return true if the input parameters are valid, false otherwise
     */
    [[nodiscard]] auto is_valid() const -> bool
    {
        return (n % 2 == 1) && (m >= MIN_PARAMS_VALUE) && (m <= MAX_PARAMS_VALUE) &&
               (n >= MIN_PARAMS_VALUE) && (n <= MAX_PARAMS_VALUE);
    }

    /**
     * Print the lines of characters
     */
    auto print_lines() const -> void
    {
        for (int line_number = 1; line_number <= n; ++line_number)
        {
            std::cout << print_line(line_number) << '\n';
        }
    }

  private:
    /**
     * The characters that would be used to print the lines that are odd
     */
    static constexpr char ODD_CHAR = '#';

    /**
     * The characters that would be used to print the lines that are even
     */
    static constexpr char EVEN_CHAR = '.';

    /**
     * Prints a string that contains the same character repeated m times
     * @param of_char the character to print
     * @return the string
     */
    [[nodiscard]] auto print_repeated_char(char of_char) const -> std::string
    {
        return std::string(static_cast<std::size_t>(m), of_char); // NOLINT(modernize-return-braced-init-list)
    }

    /**
     * Print a line of characters
     * @param line_number the number of the line to print
     * @return the line of characters
     */
    [[nodiscard]] auto print_line(int line_number) const -> std::string
    {
        std::string line;
        if (line_number % 2 == 0)
        {
            line = print_repeated_char(EVEN_CHAR);
            std::size_t pos{line_number % DIVISOR_FOR_EVEN_LINES == 0 ? 0 : line.size() - 1};
            line[pos] = ODD_CHAR;
        }
        else
        {
            line = print_repeated_char(ODD_CHAR);
        }
        return line;
    }
};

/**
 * The function that would read the input parameters n, m
 * @return the input parameters n, m wrapped in InputParams struct
 * @throws std::runtime_error if the input is invalid
 */
auto read_input() -> InputParams
{
    InputParams params{0, 0};
    if (!(std::cin >> params.n >> params.m))
    {
        throw std::runtime_error("Failed to read input");
    }
    if (!params.is_valid())
    {
        throw std::runtime_error("Invalid input parameters - please ensure values between " +
                                 std::to_string(MIN_PARAMS_VALUE) + " and " + std::to_string(MAX_PARAMS_VALUE) +
                                 " and n is odd");
    }
    return params;
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
        Solution::InputParams params{Solution::read_input()};
        params.print_lines();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}

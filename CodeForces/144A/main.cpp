/**
 * Sort your headers here
 */
#include <iostream> // for std::cin, std::cout
#include <map>      // for std::map
#include <string>   // for std::to_string
#include <vector>   // for std::vector

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

constexpr int MIN_TOTAL_ELEMENTS = 2;
constexpr int MAX_TOTAL_ELEMENTS = 100;
constexpr int MIN_ELEMENT_VALUE = 1;
constexpr int MAX_ELEMENT_VALUE = 100;

/**
 * The struct that would contain the data collected from the input
 */
struct DataCollected
{
    int min_element{MAX_ELEMENT_VALUE};
    int max_element{MIN_ELEMENT_VALUE};
    std::size_t min_element_pos{0};
    std::size_t max_element_pos{0};
    std::size_t total_elements{0};

    /**
     * Calculates the number of moves required to bring the maximum element closest to start to the 0th index and the
     * minimum element closest to end to the last index
     * @return the number of moves
     */
    [[nodiscard]] auto calculate_moves() const -> std::size_t
    {
        std::size_t total_moves{moves_for_max_element() + moves_for_min_element()};
        if (max_element_position() > min_element_position())
        {
            total_moves -= 1;
        }
        return total_moves;
    }

  private:
    /**
     * Calculates the number of moves required to bring the maximum element closest to start to the 0th index
     * @return the number of moves
     */
    [[nodiscard]] auto moves_for_max_element() const -> std::size_t
    {
        return max_element_position();
    }

    /**
     * Calculates the position of the maximum element
     * @return the position of the maximum element
     */
    [[nodiscard]] auto max_element_position() const -> std::size_t
    {
        return max_element_pos;
    }

    /**
     * Calculates the number of moves required to bring the minimum element closest to end to the last index
     * @return the number of moves
     */
    [[nodiscard]] auto moves_for_min_element() const -> std::size_t
    {
        return total_elements - min_element_position() - 1;
    }

    [[nodiscard]] auto min_element_position() const -> std::size_t
    {
        return min_element_pos;
    }
};

/**
 * Reads the total number of test cases
 * @return the total number of test cases
 */
auto read_total_test_cases() -> std::size_t
{
    int total_test_cases{};
    if (!(std::cin >> total_test_cases))
    {
        throw std::runtime_error("Failed to read input");
    }
    if (total_test_cases < MIN_TOTAL_ELEMENTS || total_test_cases > MAX_TOTAL_ELEMENTS)
    {
        throw std::runtime_error("Invalid total elements must be between " + std::to_string(MIN_TOTAL_ELEMENTS) +
                                 " and " + std::to_string(MAX_TOTAL_ELEMENTS));
    }
    return static_cast<std::size_t>(total_test_cases);
}

/**
 * Reads the input and returns the number of soldiers
 * @return the number of soldiers
 */
auto read_input() -> DataCollected
{
    DataCollected data_collected;

    data_collected.total_elements = read_total_test_cases();

    std::string errors;

    for (std::size_t i = 0; i < data_collected.total_elements; ++i)
    {
        int element{};
        if (!(std::cin >> element))
        {
            errors += "Failed to read input at index " + std::to_string(i) + "\n";
            continue;
        }

        if (element < MIN_ELEMENT_VALUE || element > MAX_ELEMENT_VALUE)
        {
            errors += "Invalid element must be between " + std::to_string(MIN_ELEMENT_VALUE) + " and " +
                      std::to_string(MAX_ELEMENT_VALUE) + " at index " + std::to_string(i) + "\n";
            continue;
        }

        if (i == 0)
        {
            data_collected.min_element = element;
            data_collected.min_element_pos = i;
            data_collected.max_element = element;
            data_collected.max_element_pos = i;
            continue;
        }

        if (element < data_collected.min_element)
        {
            data_collected.min_element = element;
            data_collected.min_element_pos = i;
        }
        else if (element == data_collected.min_element)
        {
            data_collected.min_element_pos = std::max(data_collected.min_element_pos, i);
        }
        else if (element > data_collected.max_element)
        {
            data_collected.max_element = element;
            data_collected.max_element_pos = i;
        }
        else if (element == data_collected.max_element)
        {
            data_collected.max_element_pos = std::min(data_collected.max_element_pos, i);
        }
    }

    if (!errors.empty())
    {
        throw std::runtime_error(errors);
    }

    return data_collected;
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
        auto data_collected{Solution::read_input()};
        std::cout << data_collected.calculate_moves() << '\n';
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

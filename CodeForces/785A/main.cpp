/**
 * Sort your headers here
 */
#include <cstdint>       // for std::uint8_t
#include <iostream>      // for std::cin, std::cout
#include <string>        // for std::string
#include <unordered_map> // for std::unordered_map

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

/**
 * Constructs a map of polyhedron names to the number of vertices they have
 * @return the map
 */
auto construct_polyhedron_to_number_of_vertices() -> std::unordered_map<std::string, int>
{
    return std::unordered_map<std::string, int>{
        {"Tetrahedron", 4},   // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
        {"Cube", 6},          // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
        {"Octahedron", 8},    // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
        {"Dodecahedron", 12}, // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
        {"Icosahedron", 20},  // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
    };
}

/**
 * Reads the input and returns the number of vertices of the polyhedron
 * @param polyhedron_to_number_of_vertices the map of polyhedron names to the number of vertices they have
 * @return the number of vertices of the polyhedron
 */
auto read_input(const std::unordered_map<std::string, int> &polyhedron_to_number_of_vertices) -> int
{
    std::string object_name;

    if (!(std::cin >> object_name))
    {
        throw std::runtime_error("Failed to read input");
    }

    if (polyhedron_to_number_of_vertices.count(object_name) == 0)
    {
        throw std::runtime_error("Invalid polyhedron name");
    }

    return polyhedron_to_number_of_vertices.at(object_name);
}

/**
 * Reads the total number of polyhedra present in the input
 * @return the total number of polyhedra
 */
auto read_total_number_of_polyhedra() -> int
{
    int total_number_of_polyhedra{};
    if (!(std::cin >> total_number_of_polyhedra))
    {
        throw std::runtime_error("Failed to read input");
    }

    constexpr int MIN_TOTAL_NUMBER_OF_POLYHEDRA = 1;
    constexpr int MAX_TOTAL_NUMBER_OF_POLYHEDRA = 200000;

    if (total_number_of_polyhedra < MIN_TOTAL_NUMBER_OF_POLYHEDRA ||
        total_number_of_polyhedra > MAX_TOTAL_NUMBER_OF_POLYHEDRA)
    {
        throw std::runtime_error("Invalid total number of polyhedra must be between " +
                                 std::to_string(MIN_TOTAL_NUMBER_OF_POLYHEDRA) + " and " +
                                 std::to_string(MAX_TOTAL_NUMBER_OF_POLYHEDRA));
    }

    return total_number_of_polyhedra;
}

} // namespace Solution

/**
 * Main function
 */
auto main() -> int
{
    // Fast I/O for competitive programming
    do_fast_io();

    try
    {
        auto polyhedron_to_number_of_vertices{Solution::construct_polyhedron_to_number_of_vertices()};
        auto total_number_of_polyhedra{Solution::read_total_number_of_polyhedra()};

        int total_number_of_vertices{};
        for (int i = 0; i < total_number_of_polyhedra; ++i)
        {
            total_number_of_vertices += Solution::read_input(polyhedron_to_number_of_vertices);
        }

        std::cout << total_number_of_vertices << '\n';
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

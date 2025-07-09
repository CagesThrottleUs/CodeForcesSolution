/**
 * @file main.cpp
 * @brief Solution for CodeForces 723A - Meeting point problem
 * @author CagesThrottle
 * @date 2025-07-09
 */

#include <algorithm> // for std::min, std::max
#include <cstdint>   // for std::uint8_t
#include <iostream>  // for I/O operations

/**
 * @brief Configures fast I/O for competitive programming
 */
auto configure_fast_io() -> void
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

namespace Solution
{

/** @brief Coordinate constraints for the problem */
enum class CoordinateLimit : std::uint8_t
{
    MIN = 1,
    MAX = 100
};

/**
 * @brief Represents positions of three friends on a line
 */
struct FriendPositions
{
    int position_a{};
    int position_b{};
    int position_c{};
};

/**
 * @brief Validates if a coordinate is within problem constraints
 * @param coordinate The coordinate to validate
 * @return true if coordinate is valid, false otherwise
 */
auto is_valid_coordinate(int coordinate) -> bool
{
    return coordinate >= static_cast<int>(CoordinateLimit::MIN) && coordinate <= static_cast<int>(CoordinateLimit::MAX);
}

/**
 * @brief Reads friend positions from standard input with validation
 * @param positions Reference to store the read positions
 * @return true if input is valid, false otherwise
 */
auto read_friend_positions(FriendPositions &positions) -> bool
{
    if (!(std::cin >> positions.position_a >> positions.position_b >> positions.position_c))
    {
        return false;
    }

    return is_valid_coordinate(positions.position_a) && is_valid_coordinate(positions.position_b) &&
           is_valid_coordinate(positions.position_c);
}

/**
 * @brief Computes minimum total distance for all friends to meet at one point
 * @param positions The positions of all friends
 * @return The minimum total distance required
 */
auto compute_minimum_distance(const FriendPositions &positions) -> int
{
    const int max_position = std::max({positions.position_a, positions.position_b, positions.position_c});
    const int min_position = std::min({positions.position_a, positions.position_b, positions.position_c});

    return max_position - min_position;
}

} // namespace Solution

/**
 * @brief Main function - program entry point
 * @return Exit code (0 for success, 1 for error)
 */
auto main() -> int
{
    // Configure fast I/O for competitive programming
    configure_fast_io();

    Solution::FriendPositions positions{};

    if (!Solution::read_friend_positions(positions))
    {
        std::cerr << "Error: Invalid input. Please ensure coordinates are integers between "
                  << static_cast<int>(Solution::CoordinateLimit::MIN) << " and "
                  << static_cast<int>(Solution::CoordinateLimit::MAX) << '\n';
        return 1;
    }

    std::cout << Solution::compute_minimum_distance(positions) << '\n';

    return 0;
}

#include <cstdint>
#include <iostream>

namespace constants
{
constexpr std::uint8_t DIGIT_UPPER_BOUND = 10;
constexpr std::uint8_t BASE = 10;
constexpr std::uint8_t FLIP = 9;
constexpr std::uint8_t FIVE = 5;
} // namespace constants

auto main() -> int
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::uint64_t input{}; // initial number input
    std::cin >> input;

    std::uint64_t result = 0;
    std::uint64_t multiplier = 1;
    std::uint64_t temp = input;

    // Process digits from right to left
    while (temp > 0)
    {
        auto curr_digit = static_cast<std::uint8_t>(temp % constants::BASE);
        temp /= constants::BASE;

        // Check if this is the leftmost digit (most significant)
        bool is_leftmost = (temp == 0);

        std::uint8_t digit_upper_bound = constants::DIGIT_UPPER_BOUND - static_cast<std::uint8_t>(is_leftmost);

        if (curr_digit >= constants::FIVE and curr_digit < digit_upper_bound)
        {
            result += (constants::FLIP - curr_digit) * multiplier;
        }
        else
        {
            result += curr_digit * multiplier;
        }

        multiplier *= constants::BASE;
    }

    std::cout << result << '\n';

    return 0;
}
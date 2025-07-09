#include <cstdlib>
#include <iostream>

namespace constants
{
constexpr int MATRIX_SIZE{5};
constexpr int TARGET_ROW{3};
constexpr int TARGET_COL{3};
} // namespace constants

auto main() -> int
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int pos_x{0};
    int pos_y{0};
    int val{};
    bool signal{false};

    for (int coord_x = 1; coord_x <= constants::MATRIX_SIZE; coord_x++)
    {
        for (int coord_y = 1; coord_y <= constants::MATRIX_SIZE; coord_y++)
        {
            std::cin >> val;
            if (val == 1)
            {
                pos_x = coord_x;
                pos_y = coord_y;
                signal = true;
                break;
            }
        }
        if (signal)
        {
            break;
        }
    }

    int moves = std::abs(pos_x - constants::TARGET_ROW) + std::abs(pos_y - constants::TARGET_COL);

    std::cout << moves << '\n';

    return 0;
}
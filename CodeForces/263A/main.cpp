#include <cstdlib>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int px{0}, py{0};
    int val{};
    bool signal{false};

    for (int x=1; x<=5; x++) {
        for (int y=1; y<=5; y++) {
            std::cin >> val;
            if (val == 1) {
                px = x;
                py = y;
                signal = true;
                break;
            }
        }
        if (signal) break;
    }

    int moves = std::abs(px - 3) + std::abs(py - 3);

    std::cout << moves << '\n';

    return 0;
}
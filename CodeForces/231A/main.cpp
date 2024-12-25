//
// Created by CagesThrottleUs on 25-12-2024.
//

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int total{0};

    int problems{};
    std::cin >> problems;

    for (int i{1}; i <= problems; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        total += ( (a+b+c) >= 2);
    }

    std::cout << total << '\n';

    return 0;
}

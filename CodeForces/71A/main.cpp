//
// Created by CagesThrottleUs on 25-12-2024.
//

#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n{};
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;

        if (s.length() > 10) {
            long long unsigned int num = s.length() - 2;
            std::cout << s.front() << num << s.back() << '\n';
        } else {
            std::cout << s << '\n';
        }
    }

    return 0;
}

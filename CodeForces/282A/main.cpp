#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n{};
    std::cin >> n;

    int x{0};

    while (n != 0) {
        std::string str;
        std::cin >> str;

        n--;

        if (str[1] == '+') {
            x++;
        } else if (str[1] == '-') {
            x--;
        } else {
            x += 0;
        }
    }

    std::cout << x << '\n';

    return 0;
}
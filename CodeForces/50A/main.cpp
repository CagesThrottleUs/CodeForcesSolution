#include <algorithm>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m{}, n{};
    std::cin >> m >> n;

    // std::cout << "DEBUG: (m,n)=(" << m << "," << n << ")\n";

    if (m < n) std::swap(m, n);

    const int first = (n)*(m/2) + (m % 2)*(n/2);
    const int second = (n/2)*(m) + (n % 2)*(m/2);

    // std::cout << "DEBUG: first=" << first << ", second=" << second << '\n';
    const int result = std::max(first, second);

    std::cout << result << '\n';

    return 0;
}
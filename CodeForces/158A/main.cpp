#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n{};
    int k{};
    std::cin >> n >> k;

    std::vector<int> arr;
    int kth_place{-1};

    for (int place{1}; place <= n; place++) {
        int score{};
        std::cin >> score;
        if (place == k) {
          kth_place = score;
        }
        if (score > 0) arr.emplace_back(score);
    }

    long long int valid = std::distance(arr.begin(), std::upper_bound(arr.begin(), arr.end(), kth_place,
                                                                      [](int a, int b) {
                                                                        return a > b;
                                                                      }
                                                                      )
                                        );

    std::cout << valid << "\n";
    return 0;
}
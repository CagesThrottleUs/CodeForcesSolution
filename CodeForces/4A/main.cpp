//
// Created by CagesThrottleUs on 25-12-2024.
//

#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int w;
  std::cin >> w;

  if (w & 1 || w == 2) { // odd
    std::cout << "NO" << '\n';
  } else {
    std::cout << "YES" << '\n';
  }

  return 0;
}

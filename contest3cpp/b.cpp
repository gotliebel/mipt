/*#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> colors(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> colors[i];
  }
  int m = 0;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int value = 0;
    std::cin >> value;
    auto it_first = std::lower_bound(colors.begin(), colors.end(), value);
    auto it_second = std::upper_bound(colors.begin(), colors.end(), value);
    std::cout << it_second - it_first << "\n";
  }
  return 0;
}*/
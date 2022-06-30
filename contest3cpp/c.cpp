/*#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> vector(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> vector[i];
  }
  int value = 0;
  std::cin >> value;
  std::sort(vector.begin(), vector.end());
  auto it_first = std::lower_bound(vector.begin(), vector.end(), value);
  auto it_second = std::upper_bound(vector.begin(), vector.end(), value);
  std::cout << it_second - it_first;
  return 0;
}*/
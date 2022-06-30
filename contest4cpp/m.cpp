#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vector = {1, 3, 4, 5, 6, 7, 2};
  std::sort(vector.begin(), vector.end(), [](int a, int b) {
    if (a < b) {
      return true;
    }
    return false;
  });
  for (auto i : vector) {
    std::cout << i << " ";
  }
  return 0;
}

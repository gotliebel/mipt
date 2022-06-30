/*#include <algorithm>
#include <iostream>
#include <vector>

class FenwickTree {
 public:
  explicit FenwickTree(const int &size) : ft_(size,
                                              std::vector<std::vector<int64_t>>(size,
                                                                                std::vector<int64_t>(size, 0))) {};
  void Update(const int &x, const int &y, const int &z, const int64_t &delta) {
    for (int i = x; i < ft_.size(); i = ((i | (i + 1)))) {
      for (int j = y; j < ft_.size(); j = ((j | (j + 1)))) {
        for (int k = z; k < ft_.size(); k = ((k | (k + 1)))) {
          ft_[i][j][k] += delta;
        }
      }
    }
  }
  int64_t GetSum(const int &x1, const int &y1, const int &z1, const int &x2, const int &y2, const int &z2) {
    return Sum(x2, y2, z2) - Sum(x1 - 1, y1 - 1, z1 - 1) - Sum(x1 - 1, y2, z2) - Sum(x2, y1 - 1, z2)
        - Sum(x2, y2, z1 - 1) + Sum(x1 - 1, y1 - 1, z2) + Sum(x1 - 1, y2, z1 - 1) + Sum(x2, y1 - 1, z1 - 1);
  }

 private:
  int64_t Sum(const int &x, const int &y, const int &z) {
    int64_t sum = 0;
    for (int i = x; i >= 0; i = ((i & (i + 1)) - 1)) {
      for (int j = y; j >= 0; j = ((j & (j + 1)) - 1)) {
        for (int k = z; k >= 0; k = ((k & (k + 1)) - 1)) {
          sum += ft_[i][j][k];
        }
      }
    }
    return sum;
  }
  std::vector<std::vector<std::vector<int64_t>>> ft_;
};

int main() {
  int n = 0;
  std::cin >> n;
  int operation = 0;
  FenwickTree fenwick_tree(n);
  while (true) {
    std::cin >> operation;
    if (operation == 3) {
      break;
    } else if (operation == 1) {
      int x, y, z;
      int64_t delta;
      std::cin >> x >> y >> z >> delta;
      fenwick_tree.Update(x, y, z, delta);
    } else if (operation == 2) {
      int x1, y1, z1, x2, y2, z2;
      std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
      std::cout << fenwick_tree.GetSum(x1, y1, z1, x2, y2, z2) << "\n";
    }
  }
}*/
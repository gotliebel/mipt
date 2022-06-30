/*#include <algorithm>
#include <iostream>
#include <vector>

class FenwickTree {
 public:
  explicit FenwickTree(const std::vector<int64_t> &vector) : base_(vector) {
    ft_.resize(vector.size());
    for (size_t i = 0; i < vector.size(); ++i) {
      Update(i, vector[i]);
    }
  }
  void UpdateUser(const size_t &index, const int64_t &delta) {
    int64_t new_delta = delta - base_[index];
    base_[index] = delta;
    for (size_t i = index; i < ft_.size(); i = (i | (i + 1))) {
      ft_[i] += new_delta;
    }
  }
  int64_t Sum(const int64_t &index) {
    int64_t sum = 0;
    for (int64_t i = index; i >= 0; i = ((i & (i + 1)) - 1)) {
      sum += ft_[i];
    }
    return sum;
  }
  int64_t Get(const int64_t &left, const int64_t &right) {
    return Sum(right) - Sum(left - 1);
  }

 private:
  void Update(const size_t &index, const int64_t &delta) {
    for (size_t i = index; i < ft_.size(); i = (i | (i + 1))) {
      ft_[i] += delta;
    }
  }
  std::vector<int64_t> ft_;
  std::vector<int64_t> base_;
};

int main() {
  size_t n = 0;
  std::cin >> n;
  std::vector<int64_t> mechanisms(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> mechanisms[i];
  }
  size_t m = 0;
  std::cin >> m;
  char c;
  FenwickTree fenwick_tree(mechanisms);
  int64_t left = 0, right = 0;
  for (size_t i = 0; i < m; ++i) {
    std::cin >> c;
    if (c == 's') {
      std::cin >> left >> right;
      std::cout << fenwick_tree.Get(left - 1, right - 1) << " ";
    } else {
      std::cin >> left >> right;
      fenwick_tree.UpdateUser(left - 1, right);
    }
  }
}*/
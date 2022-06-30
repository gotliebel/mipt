/*#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

class RMQ {
 public:
  explicit RMQ(const std::vector<int64_t> &vector) {
    DegreeInit(vector.size());
    sparse_table_.reserve(degree_.size());
    sparse_table_.emplace_back(vector);
    sparse_table_.resize(degree_.size());
    for (size_t i = 1; i < sparse_table_.size(); ++i) {
      sparse_table_[i].resize(vector.size());
      for (size_t j = 0; j < sparse_table_[i].size() - degree_[i - 1]; ++j) {
        sparse_table_[i][j] = std::min(sparse_table_[i - 1][j], sparse_table_[i - 1][j + degree_[i - 1]]);
      }
    }
  }
  void Get(const size_t &left, const size_t &right) {
    auto max_degree = std::upper_bound(degree_.begin(), degree_.end(), right - left + 1);
    auto max_index = std::distance(degree_.begin(), max_degree) - 1;
    std::cout << std::min(sparse_table_[max_index][left], sparse_table_[max_index][right - degree_[max_index] + 1])
              << "\n";
  }

 private:
  void DegreeInit(const size_t &size) {
    size_t deg = 1;
    degree_.reserve(size);
    while (deg <= size) {
      degree_.push_back(deg);
      deg <<= 1;
    }
  }
  std::vector<std::vector<int64_t>> sparse_table_;
  std::vector<size_t> degree_;
};

int main() {
  size_t n = 0, q = 0;
  std::cin >> n;
  std::cin >> q;
  std::vector<int64_t> releases(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> releases[i];
  }
  RMQ st(releases);
  size_t left, right;
  for (size_t i = 0; i < q; ++i) {
    std::cin >> left >> right;
    left--;
    right--;
    st.Get(left, right);
  }
  return 0;
}*/
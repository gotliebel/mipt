/*#include <algorithm>
#include <iostream>
#include <vector>

class St {
 public:
  std::vector<std::vector<int>> st_;
  std::vector<int> degree_;
  explicit St(const std::vector<int>& vector) {
    DegreeInit(vector.size());
    st_.reserve(degree_.size());
    st_.emplace_back(vector);
    st_.resize(degree_.size());
    for (size_t i = 1; i < degree_.size(); ++i) {
      st_[i].resize(vector.size());
      for (size_t j = 0; j < vector.size() - degree_[i - 1]; ++j) {
        st_[i][j] = std::min(st_[i - 1][j], st_[i - 1][j + degree_[i - 1]]);
      }
    }
  }
  int Query(const size_t& left, const size_t& right) {
    auto max_degree = std::upper_bound(degree_.begin(), degree_.end(), right - left + 1);
    auto max_index = std::distance(degree_.begin(), max_degree) - 1;
    return std::min(st_[max_index][left], st_[max_index][right - degree_[max_index] + 1]);
  }
  void DegreeInit(const size_t& n) {
    int deg = 1;
    degree_.reserve(n);
    while (deg <= n) {
      degree_.push_back(deg);
      deg *= 2;
    }
  }
};
class PrefixSum {
  std::vector<int> prefix_sum;
  PrefixSum(const std::vector<int>& vector) {
    prefix_sum.resize(vector.size());
    prefix_sum[0] = vector[0];
    for (size_t i = 1; i < vector.size(); ++i) {
      prefix_sum[i] = prefix_sum[i - 1] + vector[i];
    }
  }

};

int main() {
  std::vector<int> vector = {1, 2, 3, 0, -1, -2, 6};
  St st(vector);
  std::cout << st.Query(0, 6) << "\n";
  for (size_t i = 0; i < st.degree_.size(); ++i) {
    for (size_t j = 0; j < vector.size(); ++j) {
      std::cout << st.st_[i][j] << " ";
    }
    std::cout << "\n";
  }
  return 0;
}*/
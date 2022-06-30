/*#include <iostream>
#include <vector>

class RSQ {
 public:
  RSQ() = default;
  explicit RSQ(const std::vector<size_t> &sculptures) {
    prefix_sum_.resize(sculptures.size() + 1);
    prefix_sum_[1] = sculptures[0];
    for (size_t i = 2; i < sculptures.size() + 1; ++i) {
      prefix_sum_[i] = sculptures[i - 1] + prefix_sum_[i - 1];
    }
  }
  void Sum(const size_t &left, const size_t &right) const {
    std::cout << prefix_sum_[right] - prefix_sum_[left - 1] << " ";
  }
 private:
  std::vector<size_t> prefix_sum_;
};

int main() {
  size_t n = 0;
  size_t k = 0;
  std::cin >> n;
  std::vector<size_t> sculptures(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> sculptures[i];
  }
  RSQ prefix_sum(sculptures);
  size_t left, right;
  std::cin >> k;
  for (size_t i = 0; i < k; ++i) {
    std::cin >> left >> right;
    prefix_sum.Sum(left, right);
  }
  return 0;
}*/
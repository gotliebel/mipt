/*#include <iostream>
#include <vector>

class RSQ {
 public:
  RSQ() = default;
  explicit RSQ(const std::vector<int64_t> &suspicion) {
    prefix_sum_.resize(suspicion.size());
    prefix_sum_[0] = suspicion[0];
    for (size_t i = 1; i < suspicion.size(); ++i) {
      prefix_sum_[i] = suspicion[i] + prefix_sum_[i - 1];
    }
  }
  void LargestSum() {
    int64_t sum = prefix_sum_[0];
    int64_t min_sum = 0;
    size_t right = 0;
    size_t left = 0;
    int64_t position = -1;
    for (size_t i = 0; i < prefix_sum_.size(); ++i) {
      if (sum < prefix_sum_[i] - min_sum) {
        sum = prefix_sum_[i] - min_sum;
        left = position + 1;
        right = i;
      }
      if (min_sum > prefix_sum_[i]) {
        min_sum = prefix_sum_[i];
        position = i;
      }
    }
    std::cout << left + 1 << " " << right + 1 << " " << sum;
  }

 private:
  std::vector<int64_t> prefix_sum_;
};
int main() {
  size_t n = 0;
  std::cin >> n;
  std::vector<int64_t> suspicion(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> suspicion[i];
  }
  RSQ prefix_sum(suspicion);
  prefix_sum.LargestSum();
  return 0;
}*/
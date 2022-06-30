/*#include <algorithm>
#include <iostream>
#include <vector>

class SparseTable {
 public:
  explicit SparseTable(const std::vector<int> &vector) {
    DegreeInit(vector.size());
    sparse_table_.reserve(degree_.size());
    sparse_table_.emplace_back(vector);
    sparse_table_.resize(degree_.size());
    for (int i = 1; i < sparse_table_.size(); ++i) {
      sparse_table_[i].resize(vector.size());
      for (int j = 0; j < sparse_table_[i].size() - degree_[i - 1]; ++j) {
        sparse_table_[i][j] = std::min(sparse_table_[i - 1][j], sparse_table_[i - 1][j + degree_[i - 1]]);
      }
    }
  }
  int Get(const int &left, const int &right) {
    auto max_degree = std::upper_bound(degree_.begin(), degree_.end(), right - left + 1);
    auto max_index = std::distance(degree_.begin(), max_degree) - 1;
    auto chickibricki = std::min(sparse_table_[max_index][left], sparse_table_[max_index][right - degree_[max_index] + 1]);
    return chickibricki;
  }

 private:
  void DegreeInit(const int &size) {
    int deg = 1;
    degree_.reserve(size);
    while (deg <= size) {
      degree_.push_back(deg);
      deg <<= 1;
    }
  }
  std::vector<std::vector<int>> sparse_table_;
  std::vector<int> degree_;
};

class RSQ {
 public:
  RSQ() = default;
  explicit RSQ(const std::vector<int> &emotion) {
    prefix_sum_.resize(emotion.size());
    prefix_sum_[0] = emotion[0];
    for (int i = 1; i < emotion.size(); ++i) {
      prefix_sum_[i] = emotion[i] + prefix_sum_[i - 1];
    }
  }
  int Sum(const int& left, const int& right) {
    return prefix_sum_[right] - prefix_sum_[left - 1];
  }
  void LargestSum(const std::vector<int>& emotion) {
    SparseTable st(emotion);
    int res_left = 1;
    int res_right = prefix_sum_.size() - 1;
    int left, right;
    int current_left, current_right;
    int mid;
    int max_sum = 0, sum;
    for (int i = 1; i < prefix_sum_.size(); ++i) {
      current_left = i;
      current_right = prefix_sum_.size() - 1;
      while (current_right - current_left > 1) {
        mid = (current_right + current_left) / 2;
        if (st.Get(i, mid) == emotion[i]) {
          current_left = mid;
        } else {
          current_right = mid;
        }
      }
      if (st.Get(i, current_right) == emotion[i]) {
        right = current_right;
      } else {
        right = current_left;
      }
      current_right = i;
      current_left = 1;
      while (current_right - current_left > 1) {
        mid = (current_right + current_left) / 2;
        if (st.Get(mid, i) == emotion[i]) {
          current_right = mid;
        } else {
          current_left = mid;
        }
      }
      if (st.Get(current_left, i) == emotion[i]) {
        left = current_left;
      } else {
        left = current_right;
      }
      sum = Sum(left, right) * emotion[i];
      if (sum > max_sum) {
        max_sum = sum;
        res_left = left;
        res_right = right;
      }
    }
    std::cout << max_sum << "\n" << left << " " << right;
  }
 private:
  std::vector<int> prefix_sum_;
};

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> emotion(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> emotion[i];
  }
  RSQ prefix_sum(emotion);
  prefix_sum.LargestSum(emotion);
}*/
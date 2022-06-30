/*#include <algorithm>
#include <iostream>
#include <vector>

class SegmentTree {
 public:
  explicit SegmentTree(std::vector<int64_t> &vector) {
    size_t deg = 1;
    while (vector.size() >= deg) {
      deg <<= 1;
    }
    if (vector.size() != deg) {
      vector.resize(deg);
    }
    segment_tree_.resize(2 * vector.size() - 1);
    for (size_t i = 0; i < vector.size(); ++i) {
      segment_tree_[i + vector.size() - 1].first = vector[i];
      segment_tree_[i + vector.size() - 1].second = 1;
    }
    for (int64_t i = vector.size() - 2; i >= 0; --i) {
      segment_tree_[i].first = std::max(segment_tree_[Left(i)].first, segment_tree_[Right(i)].first);
      if (segment_tree_[Left(i)].first == segment_tree_[Right(i)].first) {
        segment_tree_[i].second = segment_tree_[Left(i)].second + segment_tree_[Right(i)].second;
      } else if (segment_tree_[i].first == segment_tree_[Left(i)].first) {
        segment_tree_[i].second = segment_tree_[Left(i)].second;
      } else {
        segment_tree_[i].second = segment_tree_[Right(i)].second;
      }
    }
  }
  auto Get(size_t left, size_t right) {
    left += segment_tree_.size() / 2;
    right += segment_tree_.size() / 2;
    std::pair<int64_t, int64_t> left_res{};
    std::pair<int64_t, int64_t> right_res{};
    while (left < right) {
      if (left == Right(Parent(left))) {
        if (left_res.first == segment_tree_[left].first) {
          left_res.second += segment_tree_[left].second;
        } else if (left_res.first < segment_tree_[left].first){
          left_res.first = segment_tree_[left].first;
          left_res.second = segment_tree_[left].second;
        }
      }
      left = Parent(left + 1);
      if (right == Left(Parent(right))) {
        if (right_res.first == segment_tree_[right].first) {
          right_res.second += segment_tree_[right].second;
        } else if (right_res.first < segment_tree_[right].first){
          right_res.first = segment_tree_[right].first;
          right_res.second = segment_tree_[right].second;
        }
      }
      right = Parent(right - 1);
    }
    if (left == right) {
      if (left_res.first == segment_tree_[left].first) {
        left_res.second += segment_tree_[left].second;
      } else if (left_res.first < segment_tree_[left].first){
        left_res.first = segment_tree_[left].first;
        left_res.second = segment_tree_[left].second;
      }
    }
    if (left_res.first == right_res.first) {
      return std::pair<int64_t, int64_t>(left_res.first, left_res.second + right_res.second);
    }
    if (left_res.first < right_res.first) {
      return right_res;
    }
    return left_res;
  }
 private:
  size_t Parent(const size_t &index) {
    return (index - 1) / 2;
  }
  size_t Left(const size_t &index) {
    return 2 * index + 1;
  }
  size_t Right(const size_t &index) {
    return 2 * index + 2;
  }
  std::vector<std::pair<int64_t, int64_t>> segment_tree_;
};

int main() {
  size_t n, k;
  std::cin >> n;
  std::vector<int64_t> subscribers(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> subscribers[i];
  }
  std::cin >> k;
  int64_t left, right;
  SegmentTree segment_tree(subscribers);
  for (size_t i = 0; i < k; ++i) {
    std::cin >> left >> right;
    std::cout << segment_tree.Get(left - 1, right - 1).first << " " << segment_tree.Get(left - 1, right - 1).second
              << "\n";
  }
  return 0;
}*/
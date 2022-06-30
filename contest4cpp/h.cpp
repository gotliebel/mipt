/*#include <algorithm>
#include <iostream>
#include <vector>

class SegmentTree {
 public:
  explicit SegmentTree(std::vector<int64_t> &vector) {
    int64_t deg = 1;
    while (vector.size() >= deg) {
      deg <<= 1;
    }
    if (vector.size() != deg) {
      vector.resize(deg);
    }
    segment_tree_.resize(2 * vector.size() - 1);
    for (size_t i = 0; i < vector.size(); ++i) {
      segment_tree_[i + vector.size() - 1].first = vector[i];
      segment_tree_[i + vector.size() - 1].second = 0;
    }
    for (int64_t i = vector.size() - 2; i >= 0; --i) {
      segment_tree_[i].first = std::max(segment_tree_[Left(i)].first, segment_tree_[Right(i)].first);
    }
  }
  int64_t Get(const size_t &left, const size_t &right, size_t node, size_t node_left, size_t node_right) {
    if (left <= node_left && right >= node_right) {
      return segment_tree_[node].first + segment_tree_[node].second;
    }
    if (left > node_right || right < node_left) {
      return 0;
    }
    int64_t left_res = 0;
    int64_t right_res = 0;
    Push(node);
    left_res = Get(left, right, Left(node), node_left, (node_left + node_right) / 2);
    right_res = Get(left, right, Right(node), (node_left + node_right) / 2 + 1, node_right);
    return std::max(left_res, right_res);
  }
  void Update(const size_t &left,
              const size_t &right,
              size_t node,
              size_t node_left,
              size_t node_right,
              const int64_t &delta) {
    if (left <= node_left && right >= node_right) {
      segment_tree_[node].second += delta;
      return;
    }
    if (left > node_right || right < node_left) {
      return;
    }
    Push(node);
    Update(left, right, Left(node), node_left, (node_left + node_right) / 2, delta);
    Update(left, right, Right(node), (node_left + node_right) / 2 + 1, node_right, delta);
    segment_tree_[node].first = std::max(segment_tree_[Left(node)].first + segment_tree_[Left(node)].second,
                                         segment_tree_[Right(node)].first + segment_tree_[Right(node)].second);
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
  void Push(const size_t &node) {
    segment_tree_[node].first += segment_tree_[node].second;
    segment_tree_[Left(node)].second += segment_tree_[node].second;
    segment_tree_[Right(node)].second += segment_tree_[node].second;
    segment_tree_[node].second = 0;
  }
  std::vector<std::pair<int64_t, int64_t>> segment_tree_;
};

int main() {
  size_t n, m;
  std::cin >> n;
  std::vector<int64_t> honey(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> honey[i];
  }
  std::cin >> m;
  char operation;
  int64_t left, right;
  int64_t delta;
  SegmentTree segment_tree(honey);
  for (size_t i = 0; i < m; ++i) {
    std::cin >> operation;
    if (operation == 'a') {
      std::cin >> left >> right >> delta;
      segment_tree.Update(left - 1, right - 1, 0, 0, honey.size() - 1, delta);
    } else {
      std::cin >> left >> right;
      std::cout << segment_tree.Get(left - 1, right - 1, 0, 0, honey.size() - 1) << " ";
    }
  }
  return 0;
}*/
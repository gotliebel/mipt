/*#include <iostream>
#include <vector>

class SegmentTree {
 public:
  explicit SegmentTree(size_t& n) {
    size_t deg = 1;
    while (n >= deg) {
      deg <<= 1;
    }
    if (n != deg) {
      n = deg;
    }
    segment_tree_.resize(2 * n - 1);
    for (size_t i = 0; i < n; ++i) {
      segment_tree_[i + n - 1] = Node(0, 0, 1);
    }
    for (int64_t i = n - 2; i >= 0; --i) {
      segment_tree_[i] = Node(0, 0, segment_tree_[Left(i)].size_ + segment_tree_[Right(i)].size_);
    }
  }
  int64_t Get(const size_t& left, const size_t& right, size_t node, size_t node_left, size_t node_right) {
    if (left <= node_left && right >= node_right) {
      return segment_tree_[node].value_ + segment_tree_[node].promise_ * segment_tree_[node].size_;
    }
    if (left > node_right || right < node_left) {
      return 0;
    }
    int64_t left_res = 0;
    int64_t right_res = 0;
    Push(node);
    left_res = Get(left, right, Left(node), node_left, (node_left + node_right) / 2);
    right_res = Get(left, right, Right(node), (node_left + node_right) / 2 + 1, node_right);
    return left_res + right_res;
  }
  void Update(const size_t& left, const size_t& right, size_t node, size_t node_left, size_t node_right,
              const int64_t& delta) {
    if (left <= node_left && right >= node_right) {
      segment_tree_[node].promise_ += delta;
      return;
    }
    if (left > node_right || right < node_left) {
      return;
    }
    Push(node);
    Update(left, right, Left(node), node_left, (node_left + node_right) / 2, delta);
    Update(left, right, Right(node), (node_left + node_right) / 2 + 1, node_right, delta);
    segment_tree_[node].value_ =
        segment_tree_[Left(node)].value_ + segment_tree_[Left(node)].promise_ * segment_tree_[Left(node)].size_ +
            segment_tree_[Right(node)].value_ + segment_tree_[Right(node)].promise_ * segment_tree_[Right(node)].size_;
  }

 private:
  size_t Parent(const size_t& index) {
    return (index - 1) / 2;
  }
  size_t Left(const size_t& index) {
    return 2 * index + 1;
  }
  size_t Right(const size_t& index) {
    return 2 * index + 2;
  }
  void Push(const size_t& node) {
    segment_tree_[node].value_ += segment_tree_[node].promise_ * segment_tree_[node].size_;
    segment_tree_[Left(node)].promise_ += segment_tree_[node].promise_;
    segment_tree_[Right(node)].promise_ += segment_tree_[node].promise_;
    segment_tree_[node].promise_ = 0;
  }
  struct Node {
    int value_;
    int promise_;
    int size_;
    Node() = default;
    Node(const int& value, const int& promise, const int& size) : value_(value), promise_(promise), size_(size) {};
  };
  std::vector<Node> segment_tree_;
};

int main() {
  size_t n = 0, m = 0;
  std::cin >> n >> m;
  size_t operation = 0;
  size_t left, right;
  int number_objects;
  SegmentTree rooms(n);
  for (size_t i = 0; i < m; ++i) {
    std::cin >> operation;
    std::cin >> left >> right;
    if (operation == 1) {
      std::cin >> number_objects;
      rooms.Update(left, right - 1, 0, 0, n - 1, number_objects);
    } else {
      std::cout << rooms.Get(left, right - 1, 0, 0, n - 1) << "\n";
    }
  }
}*/
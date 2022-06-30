/*#include <algorithm>
#include <iostream>
#include <vector>

class CartesianTree {
 private:
  struct Node {
    Node* parent_;
    Node* left_child_;
    Node* right_child_;
    std::pair<int64_t, int64_t> key_priority_;
    int64_t size_;
    int64_t result_;
    Node() = default;
    Node(const std::pair<int64_t, int64_t>& key_prior, const int64_t& size, const int64_t& result)
        : parent_(nullptr)
        , left_child_(nullptr)
        , right_child_(nullptr)
        , key_priority_(key_prior)
        , size_(size)
        , result_(result){};
  };

 public:
  CartesianTree() = default;
  void Insert(const size_t& index, const int& key) {
    auto tree_less_more = Split(root_, index);
    Node* new_node = new Node({key, rand() % 100000}, 1, key);
    root_ = Merge(Merge(tree_less_more.first, new_node), tree_less_more.second);
    FixNode(new_node);
  }
  int64_t Query(const size_t& left, const size_t& right) {
    auto tree_less_more_left = Split(root_, left);
    auto tree_less_more_right = Split(tree_less_more_left.second, right - left);
    int64_t result = tree_less_more_right.first->result_;
    root_ = Merge(Merge(tree_less_more_left.first, tree_less_more_right.first), tree_less_more_right.second);
    return result;
  }

  Node* GetRoot() {
    return root_;
  }
  ~CartesianTree() {
    Clear(root_);
  }

 private:
  Node* Merge(Node* root_first, Node* root_second) {
    if (root_first == nullptr) {
      return root_second;
    }
    if (root_second == nullptr) {
      return root_first;
    }
    if (root_first->key_priority_.second < root_second->key_priority_.second) {
      root_first->right_child_ = Merge(root_first->right_child_, root_second);
      root_first->right_child_->parent_ = root_first;
      FixNode(root_first);
      return root_first;
    }
    root_second->left_child_ = Merge(root_first, root_second->left_child_);
    root_second->left_child_->parent_ = root_second;
    FixNode(root_second);
    return root_second;
  }
  std::pair<Node*, Node*> Split(Node* node, const int& size) {
    if (node == nullptr) {
      return {nullptr, nullptr};
    }
    if (Size(node->left_child_) < size) {
      auto two_trees = Split(node->right_child_, size - Size(node->left_child_) - 1);
      node->right_child_ = two_trees.first;
      if (two_trees.first != nullptr) {
        two_trees.first->parent_ = node;
      }
      if (two_trees.second != nullptr) {
        two_trees.second->parent_ = nullptr;
      }
      FixNode(node);
      return {node, two_trees.second};
    }
    auto two_trees = Split(node->left_child_, size);
    node->left_child_ = two_trees.second;
    if (two_trees.first != nullptr) {
      two_trees.first->parent_ = nullptr;
    }
    if (two_trees.second != nullptr) {
      two_trees.second->parent_ = node;
    }
    FixNode(node);
    return {two_trees.first, node};
  }
  void FixNode(Node* node) {
    node->size_ = 1 + Size(node->left_child_) + Size(node->right_child_);
    int64_t min = 999999999999999999;
    if (node->left_child_ != nullptr) {
      min = std::min(node->key_priority_.first, node->left_child_->result_);
    }
    if (node->right_child_ != nullptr) {
      min = std::min(node->key_priority_.first, std::min(min, node->right_child_->result_));
    }
    if (node->left_child_ == nullptr && node->right_child_ == nullptr) {
      node->result_ = node->key_priority_.first;
      return;
    }
    node->result_ = min;
  }
  int64_t Size(const Node* node) const {
    return ((node != nullptr) ? node->size_ : 0);
  }
  void Clear(Node* node) {
    if (node != nullptr) {
      Clear(node->left_child_);
      Clear(node->right_child_);
      delete node;
    }
  }
  Node* root_;
};
int main() {
  size_t n = 0;
  std::cin >> n;
  char operation;
  size_t left, right, index;
  int value;
  CartesianTree treap{};
  for (size_t i = 0; i < n; ++i) {
    std::cin >> operation;
    if (operation == '+') {
      std::cin >> index >> value;
      treap.Insert(index, value);
    } else {
      std::cin >> left >> right;
      std::cout << treap.Query(left - 1, right) << "\n";
    }
  }
}*/
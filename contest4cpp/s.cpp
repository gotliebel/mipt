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
    bool promise_reverse_;
    Node() = default;
    Node(const std::pair<int64_t, int64_t>& key_prior, const int64_t& size, const int64_t& result, bool promise)
        : parent_(nullptr)
        , left_child_(nullptr)
        , right_child_(nullptr)
        , key_priority_(key_prior)
        , size_(size)
        , result_(result)
        , promise_reverse_(promise){};
  };

 public:
  CartesianTree() = default;
  explicit CartesianTree(const std::vector<int>& vector) {
    root_ = new Node({vector[0], rand() % 100001}, 1, vector[0], false);
    Node* last_inserted = root_;
    for (size_t i = 1; i < vector.size(); ++i) {
      Node* currently = last_inserted;
      Node* node = new Node({vector[i], rand() % 100001}, 1, vector[i], false);
      while (currently != nullptr && currently->key_priority_.second > node->key_priority_.second) {
        currently = currently->parent_;
      }
      if (currently == nullptr) {
        node->left_child_ = root_;
        FixNode(node);
        if (root_ != nullptr) {
          root_->parent_ = node;
        }
        root_ = node;
      } else {
        node->left_child_ = currently->right_child_;
        if (currently->right_child_ != nullptr) {
          currently->right_child_->parent_ = node;
        }
        currently->right_child_ = node;
        node->parent_ = currently;
        Node* tmp = node;
        FixNode(node);
        while (tmp != root_) {
          tmp = tmp->parent_;
          FixNode(tmp);
        }
      }
      last_inserted = node;
    }
  }
  void Reverse(const size_t& left, const size_t& right) {
    auto tree_less_more_left = Split(root_, left);
    auto tree_less_more_right = Split(tree_less_more_left.second, right - left);
    if (tree_less_more_right.first != nullptr) {
      if (tree_less_more_right.first->promise_reverse_) {
        tree_less_more_right.first->promise_reverse_ = false;
      } else {
        tree_less_more_right.first->promise_reverse_ = true;
      }
    }
    root_ = Merge(Merge(tree_less_more_left.first, tree_less_more_right.first), tree_less_more_right.second);
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
  void Push(Node* node) {
    if (node != nullptr && node->promise_reverse_) {
      if (node->right_child_ != nullptr) {
        node->right_child_->promise_reverse_ = !node->right_child_->promise_reverse_;
      }
      if (node->left_child_ != nullptr) {
        node->left_child_->promise_reverse_ = !node->left_child_->promise_reverse_;
      }
      node->promise_reverse_ = false;
      std::swap(node->left_child_, node->right_child_);
    }
  }
  Node* Merge(Node* root_first, Node* root_second) {
    if (root_first == nullptr) {
      return root_second;
    }
    if (root_second == nullptr) {
      return root_first;
    }
    if (root_first->key_priority_.second < root_second->key_priority_.second) {
      Push(root_first);
      root_first->right_child_ = Merge(root_first->right_child_, root_second);
      root_first->right_child_->parent_ = root_first;
      FixNode(root_first);
      return root_first;
    }
    Push(root_second);
    root_second->left_child_ = Merge(root_first, root_second->left_child_);
    root_second->left_child_->parent_ = root_second;
    FixNode(root_second);
    return root_second;
  }
  std::pair<Node*, Node*> Split(Node* node, const int& size) {
    if (node == nullptr) {
      return {nullptr, nullptr};
    }
    Push(node);
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
  size_t n, m;
  std::cin >> n >> m;
  std::vector<int> numbers(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }
  CartesianTree treap(numbers);
  size_t left, right, operation;
  for (size_t i = 0; i < m; ++i) {
    std::cin >> operation;
    std::cin >> left >> right;
    if (operation == 1) {
      treap.Reverse(left - 1, right);
    } else {
      std::cout << treap.Query(left - 1, right) << "\n";
    }
  }
  return 0;
}*/
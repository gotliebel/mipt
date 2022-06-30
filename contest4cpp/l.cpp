/*#include <iostream>

class CartesianTree {
 private:
  struct Node {
    Node* parent_;
    Node* left_child_;
    Node* right_child_;
    std::pair<int, int> key_priority_;
    int64_t size_;
    Node() = default;
    Node(const std::pair<int, int>& key_prior, const int64_t& size)
        : parent_(nullptr), left_child_(nullptr), right_child_(nullptr), key_priority_(key_prior), size_(size){};
  };

 public:
  CartesianTree() = default;
  explicit CartesianTree(const size_t& size) {
    root_ = new Node({1, rand() % 100001}, 1);
    Node* last_inserted = root_;
    for (size_t i = 2; i <= size; ++i) {
      Node* currently = last_inserted;
      Node* node = new Node({i, rand() % 100001}, 1);
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
  void Change(const size_t& left, const size_t& right) {
    auto tree_less_more_left = Split(root_, left);
    auto tree_less_more_right = Split(tree_less_more_left.second, right - left);
    root_ = Merge(Merge(tree_less_more_right.first, tree_less_more_left.first), tree_less_more_right.second);
  }
  void Inorder(Node* node) const {
    if (node == nullptr) {
      return;
    }
    Inorder(node->left_child_);
    std::cout << node->key_priority_.first << " ";
    Inorder(node->right_child_);
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
  std::pair<Node*, Node*> Split(Node* node, const int64_t& size) {
    if (node == nullptr) {
      return {nullptr, nullptr};
    }
    if (Result(node->left_child_) < size) {
      auto two_trees = Split(node->right_child_, size - Result(node->left_child_) - 1);
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
    node->size_ = 1 + Result(node->left_child_) + Result(node->right_child_);
  }
  int64_t Result(const Node* node) const {
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
  CartesianTree treap(n);
  size_t left, right;
  while (m > 0) {
    std::cin >> left >> right;
    treap.Change(left - 1, right);
    m--;
  }
  treap.Inorder(treap.GetRoot());
}*/
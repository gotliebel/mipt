/*#include <iostream>
#include <memory>
#include <vector>

class CartesianTree {
 private:
  struct Node {
    std::shared_ptr<Node> left_child;
    Node* parent_;
    Node* left_child_;
    Node* right_child_;
    std::pair<int, int> key_priority_;
    size_t index_;
    Node() = default;
    Node(const std::pair<int, int>& data, const size_t& index)
        : key_priority_(data), left_child_(nullptr), right_child_(nullptr), parent_(nullptr), index_(index) {};
  };

 public:
  CartesianTree() = default;
  explicit CartesianTree(const std::vector<std::pair<int, int>>& vector) {
    root_ = new Node(vector[0], 1);
    Node* last_inserted = root_;
    for (size_t i = 1; i < vector.size(); ++i) {
      Node* currently = last_inserted;
      Node* node = new Node(vector[i], i + 1);
      while (currently != nullptr && currently->key_priority_.second > node->key_priority_.second) {
        currently = currently->parent_;
      }
      if (currently == nullptr) {
        node->left_child_ = root_;
        root_->parent_ = node;
        if (root_->parent_->key_priority_ >= node->key_priority_) {
          root_ = node;
        }
      } else {
        node->left_child_ = currently->right_child_;
        if (currently->right_child_) {
          currently->right_child_->parent_ = node;
        }
        currently->right_child_ = node;
        node->parent_ = currently;
      }
      last_inserted = node;
    }
  }
  void Inorder(Node* node) {
    if (node == nullptr) {
      return;
    }
    Inorder(node->left_child_);
    if (node->parent_ != nullptr) {
      std::cout << node->parent_->index_ << " ";
    } else {
      std::cout << 0 << " ";
    }
    if (node->left_child_ != nullptr) {
      std::cout << node->left_child_->index_ << " ";
    } else {
      std::cout << 0 << " ";
    }
    if (node->right_child_ != nullptr) {
      std::cout << node->right_child_->index_ << "\n";
    } else {
      std::cout << 0 << "\n";
    }
    Inorder(node->right_child_);
  }
  Node* GetRoot() const {
    return root_;
  }
  ~CartesianTree() {
    Clear(root_);
  }
 private:
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
  std::vector<std::pair<int, int>> vector(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> vector[i].first >> vector[i].second;
  }
  CartesianTree treap(vector);
  std::cout << "YES" << "\n";
  treap.Inorder(treap.GetRoot());
  return 0;
}*/
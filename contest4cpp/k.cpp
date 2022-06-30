/*#include <iostream>

class CartesianTree {
 private:
  struct Node {
    Node* parent_;
    Node* left_child_;
    Node* right_child_;
    std::pair<int, int> key_priority_;
    int64_t result_;
    Node() = default;
    Node(const std::pair<int, int>& key_prior, const int64_t& result)
        : parent_(nullptr), left_child_(nullptr), right_child_(nullptr),
          key_priority_(key_prior), result_(result) {};
  };

 public:
  CartesianTree() = default;
  void Insert(const int& key) {
    if (!Exist(root_, key)) {
      auto tree_less_more = Split(root_, key);
      Node* new_node = new Node({key, rand() % 10000000}, key);
      root_ =
          Merge(Merge(tree_less_more.first, new_node), tree_less_more.second);
    }
  }
  int64_t Query(const int& left, const int& right) {
    auto tree_less_more_left = Split(root_, left);
    auto tree_less_more_right = Split(tree_less_more_left.second, right);
    int64_t result = Result(tree_less_more_right.first);
    root_ = Merge(Merge(tree_less_more_left.first, tree_less_more_right.first), tree_less_more_right.second);
    return result;
  }
  ~CartesianTree() { Clear(root_); }

 private:
  bool Exist(Node* node, const int& key) const {
    if (node == nullptr) {
      return false;
    }
    if (node->key_priority_.first == key) {
      return true;
    }
    if (node->key_priority_.first < key) {
      return Exist(node->right_child_, key);
    }
    return Exist(node->left_child_, key);
  }
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
  std::pair<Node*, Node*> Split(Node* node, const int64_t& key) {
    if (node == nullptr) {
      return {nullptr, nullptr};
    }
    if (node->key_priority_.first < key) {
      auto two_trees = Split(node->right_child_, key);
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
    auto two_trees = Split(node->left_child_, key);
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
    node->result_ = Result(node->left_child_) + node->key_priority_.first + Result(node->right_child_);
  }
  int64_t Result(Node* node) { return ((node != nullptr) ? node->result_ : 0); }
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
  int n = 0;
  std::cin >> n;
  CartesianTree treap{};
  char operation;
  int value;
  int left, right;
  while (n > 0) {
    std::cin >> operation;
    if (operation == '+') {
      std::cin >> value;
      treap.Insert(value);
      n--;
    } else {
      std::cin >> left >> right;
      std::cout << treap.Query(left, right + 1) << "\n";
      n--;
    }
  }
  return 0;
}*/
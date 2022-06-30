/*#include <iostream>
#include <string>

class CartesianTree {
 public:
  struct Node {
    Node* parent_;
    Node* left_child_;
    Node* right_child_;
    std::pair<int, int> key_priority_;
    int size_;
    Node() = default;
    Node(const std::pair<int, int>& key_prior, const int& size = 1)
        : parent_(nullptr), left_child_(nullptr), right_child_(nullptr),
          key_priority_(key_prior), size_(size) {};
  };

 public:
  CartesianTree() = default;
  void Insert(const int& key) {
    if (!Exist(root_, key)) {
      auto tree_less_more = Split(root_, key);
      Node* new_node = new Node({key, rand() % 10000000}, 1);
      root_ =
          Merge(Merge(tree_less_more.first, new_node), tree_less_more.second);
    }
  }
  void Erase(const int& key) {
    if (Exist(root_, key)) {
      auto tree_less_more = Split(root_, key);
      auto tree_equal_more = Split(tree_less_more.second, key + 1);
      delete tree_equal_more.first;
      root_ = Merge(tree_less_more.first, tree_equal_more.second);
    }
  }
  Node* GetRoot() const { return root_; }
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
  Node* Next(const int& value) const {
    Node* next = nullptr;
    Node* cur = root_;
    while (cur != nullptr) {
      if (cur->key_priority_.first > value) {
        next = cur;
        cur = cur->left_child_;
      } else {
        cur = cur->right_child_;
      }
    }
    return next;
  }
  Node* Prev(const int& value) const {
    Node* prev = nullptr;
    Node* cur = root_;
    while (cur != nullptr) {
      if (cur->key_priority_.first < value) {
        prev = cur;
        cur = cur->right_child_;
      } else {
        cur = cur->left_child_;
      }
    }
    return prev;
  }
  Node* KthElement(int k) {
    Node* node = root_;
    while (node != nullptr) {
      if (node->left_child_ != nullptr && node->left_child_->size_ < k) {
        k -= node->left_child_->size_ + 1;
        node = node->right_child_;
      } else if (node->left_child_ != nullptr && node->left_child_->size_ > k) {
        node = node->left_child_;
      } else {
        return node;
      }
    }
    return nullptr;
  }
  ~CartesianTree() { Clear(root_); }

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
    } else {
      root_second->left_child_ = Merge(root_first, root_second->left_child_);
      root_second->left_child_->parent_ = root_second;
      FixNode(root_second);
      return root_second;
    }
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
    } else {
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
  }
  void FixNode(Node* node) {
    node->size_ = 1 + Result(node->left_child_) + Result(node->right_child_);
  }
  int Result(Node* node) { return ((node != nullptr) ? node->size_ : 0); }
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
  std::string command;
  CartesianTree treap{};
  int value;
  while (std::cin >> command) {
    if (command == "insert") {
      std::cin >> value;
      treap.Insert(value);
    } else if (command == "delete") {
      std::cin >> value;
      treap.Erase(value);
    } else if (command == "exists") {
      std::cin >> value;
      if (treap.Exist(treap.GetRoot(), value)) {
        std::cout << "true\n";
      } else {
        std::cout << "false\n";
      }
    } else if (command == "next") {
      std::cin >> value;
      CartesianTree::Node* tmp = treap.Next(value);
      if (tmp == nullptr) {
        std::cout << "none\n";
      } else {
        std::cout << tmp->key_priority_.first << "\n";
      }
    } else if (command == "prev") {
      std::cin >> value;
      CartesianTree::Node* tmp = treap.Prev(value);
      if (tmp == nullptr) {
        std::cout << "none\n";
      } else {
        std::cout << tmp->key_priority_.first << "\n";
      }
    } else if (command == "kth") {
      std::cin >> value;
      CartesianTree::Node* tmp = treap.KthElement(value);
      if (tmp == nullptr) {
        std::cout << "none\n";
      } else {
        std::cout << tmp->key_priority_.first << "\n";
      }
    }
  }
  return 0;
}*/
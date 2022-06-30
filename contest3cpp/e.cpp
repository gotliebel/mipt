/*#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  std::cin >> n;
  std::unordered_map<std::string, std::string> dict(n);
  std::unordered_map<std::string, std::string> dict_reverse(n);
  std::string key;
  std::string value;
  for (int i = 0; i < n; ++i) {
    std::cin >> key;
    std::cin >> value;
    dict[key] = value;
    dict_reverse[value] = key;
  }
  int q = 0;
  std::cin >> q;
  std::string word;
  for (int i = 0; i < q; ++i) {
    std::cin >> word;
    if (dict.find(word) != dict.end()) {
      std::cout << dict[word] << "\n";
    } else {
      std::cout << dict_reverse[word] << "\n";
    }
  }
}*/
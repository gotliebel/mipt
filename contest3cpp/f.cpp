/*#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  int n = 0;
  std::cin >> n;
  std::unordered_map<std::string, int64_t>dict;
  int operation = 0;
  int amount = 0;
  std::string name;
  for (int i = 0; i < n; ++i) {
    std::cin >> operation;
    std::cin >> name;
    if (operation == 1) {
      std::cin >> amount;
      dict[name] += amount;
    } else {
      if (dict.find(name) == dict.end()) {
        std::cout << "ERROR\n";
      } else {
        std::cout << dict[name] << "\n";
      }
    }
  }
  return 0;
}*/
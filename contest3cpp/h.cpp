/*#include <iostream>
#include <map>

int main() {
  std::string name;
  std::string object;
  int64_t count = 0;
  std::map<std::string, std::map<std::string, int64_t>> dict;
  while (std::cin >> name) {
    std::cin >> object;
    std::cin >> count;
    dict[name][object] += count;
  }
  for (const auto& i : dict) {
    std::cout << i.first << ":\n";
    for (const auto& j : i.second) {
      std::cout << j.first << " " << j.second << "\n";
    }
  }
}*/
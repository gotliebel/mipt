/*#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

int main() {
  std::string word;
  std::map<std::string, int> dict;
  while (std::cin >> word) {
    dict[word] += 1;
  }
  std::map<int, std::vector<std::string>> dict_reverse;
  std::vector<std::pair<int, std::string>> vector;
  for (const auto &i : dict) {
    vector.emplace_back(i.second, i.first);
    dict_reverse[i.second].push_back(i.first);
  }
  std::sort(vector.begin(), vector.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
    return (a.first > b.first ? 1 : a.first < b.first ? 0 : a.second < b.second ? 1 : 0);
  });
  for (auto & i : vector) {
    std::cout << i.second << "\n";
  }
  return 0;
}*/

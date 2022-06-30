/*#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  int k = 0;
  std::cin >> k;
  std::vector<std::vector<int>> graph(n + 1);
  int u, v;
  int operation = 0;
  for (int i = 0; i < k; ++i) {
    std::cin >> operation;
    if (operation == 1) {
      std::cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    } else {
      std::cin >> u;
      for (int j : graph[u]) {
        std::cout << j << " ";
      }
      std::cout << "\n";
    }
  }
}*/
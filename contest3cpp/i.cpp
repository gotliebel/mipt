/*#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int64_t n = 0;
  std::cin >> n;
  std::vector<int64_t> coins(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> coins[i];
  }
  std::make_heap(coins.begin(), coins.end(), std::greater<>{});
  double sum = 0;
  while (coins.size() > 1) {
    int64_t coin_first, coin_second;
    coin_first = coins.front();
    std::pop_heap(coins.begin(), coins.end(), std::greater<>{});
    coins.pop_back();
    coin_second = coins.front();
    std::pop_heap(coins.begin(), coins.end(), std::greater<>{});
    coins.pop_back();
    sum += (coin_first + coin_second) * 0.05;
    coins.push_back(coin_first + coin_second);
  }
  std::cout << sum;
  return 0;
}*/
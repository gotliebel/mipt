#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

struct Compare {
  bool operator()(const std::pair<int, int> &first, const std::pair<int, int> &second) const {
    if (first.first > second.first) {
      return true;
    }
    if (first.first == second.first && first.second < second.second) {
      return true;
    }
    return false;
  }
};

class Radio {
 public:
  Radio() {
    for (size_t i = 0; i < 100001; ++i) {
      id_score_.insert({i + 1, 0});
      set_score_id_.insert({0, i + 1});
    }
  }
  void Get() {
    std::cout << set_score_id_.begin()->second << " " << set_score_id_.begin()->first << "\n";
    size_t id = set_score_id_.begin()->second;
    set_score_id_.erase({set_score_id_.begin()->first, id});
    set_score_id_.insert({-1, id});
    id_score_[id] = -1;
  }
  void Vote() {
    std::string ip;
    int id, score, time;
    std::cin >> ip >> id >> score >> time;
    if (ip_time_.find(ip) == ip_time_.end() || (time - ip_time_[ip] >= 600)) {
      set_score_id_.erase({id_score_[id], id});
      set_score_id_.insert({id_score_[id] + score, id});
      id_score_[id] += score;
      ip_time_[ip] = time;
    }
    std::cout << id_score_[id] << "\n";
  }

 private:
  std::unordered_map<size_t, int> id_score_;
  std::unordered_map<std::string, size_t> ip_time_;
  std::set<std::pair<int, int>, Compare, std::allocator<std::pair<int, int> >> set_score_id_;
};

int main() {
  std::string command;
  Radio radio;
  while (std::cin >> command) {
    if (command == "EXIT") {
      std::cout << "OK";
      break;
    }
    if (command == "VOTE") {
      radio.Vote();
    } else if (command == "GET") {
      radio.Get();
    }
  }
  return 0;
}
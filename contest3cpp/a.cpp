  /*#include <iostream>
  #include <vector>
  #include <algorithm>

  struct ACM {
    int counter_tasks = 0;
    int fine = 0;
    int number_task = 0;
  };
  bool comp(ACM first, ACM second) {
    return (first.counter_tasks > second.counter_tasks ? 1 : first.counter_tasks != second.counter_tasks ? 0 : first.fine
                                                                                                                   < second.fine
                                                                                                               ? 1 :
                                                                                                               first.fine
                                                                                                                   != second.fine
                                                                                                               ? 0 :
                                                                                                               first.number_task
                                                                                                                   > second.number_task
                                                                                                               ? 0 : 1);
  }
  int main() {
    int n = 0;
    std::cin >> n;
    std::vector<ACM> vector(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> vector[i].counter_tasks;
      std::cin >> vector[i].fine;
      vector[i].number_task = i + 1;
    }
    std::sort(vector.begin(), vector.end(), comp);
    for (int i = 0; i < n; ++i) {
      std::cout << vector[i].number_task << "\n";
    }
    return 0;
  }
  */
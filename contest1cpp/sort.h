#ifndef CONTEST1_SORT_H
#define CONTEST1_SORT_H
#include <cstdint>

template <class T>
void Merge(T* begin, T* mid, T* end) {
  int first_index = 0;
  int second_index = 0;
  const int len = end - begin;
  auto* arr = new T[len]();
  while (first_index + begin < mid && second_index + mid < end) {
    if (begin[first_index] < mid[second_index]) {
      arr[first_index + second_index] = begin[first_index];
      first_index++;
    } else {
      arr[first_index + second_index] = mid[second_index];
      second_index++;
    }
  }
  while (first_index + begin < mid) {
    arr[first_index + second_index] = begin[first_index];
    first_index++;
  }
  while (second_index + mid < end) {
    arr[first_index + second_index] = mid[second_index];
    second_index++;
  }
  for (int i = 0; i < first_index + second_index; ++i) {
    begin[i] = arr[i];
  }
  delete[] arr;
}

template <class T>
void Sort(T* begin, T* end) {
  if (end < begin + 2) {
    return;
  }
  std::size_t size = end - begin;
  Sort(begin, &begin[size / 2]);
  Sort(&begin[size / 2], end);
  Merge(begin, &begin[size / 2], end);
}

#endif
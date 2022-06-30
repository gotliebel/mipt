#ifndef CONTEST1_BINSEARCH_H
#define CONTEST1_BINSEARCH_H
#include <cstdint>

template <class T>
bool BinarySearch(const T* begin, const T* end, const T& target) {
  while (begin < end - 1) {
    std::size_t size = end - begin;
    if (target < begin[size / 2]) {
      end = &(begin[size / 2]);
    } else if (begin[size / 2] < target) {
      begin = &(begin[size / 2]);
    } else {
      return true;
    }
  }
  return !(begin[0] < target) && !(target < begin[0]);
}
#endif
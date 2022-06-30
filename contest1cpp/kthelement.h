#ifndef CONTEST1_KTHELEMENT_H
#define CONTEST1_KTHELEMENT_H

template <class T>
void Swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <class T>
T* Partition(T* beg, T* end) {
  T pv = *beg;
  int pp = 0;
  int size = end - beg;
  for (int i = 0; i < size; ++i) {
    if (beg[i] < pv) {
      pp++;
      Swap(beg[i], beg[pp]);
    }
  }
  Swap(beg[pp], beg[0]);
  return &beg[pp];
}

template <class T>
void KthElement(T* begin, T* kth, T* end) {
  while (true) {
    T* mid = Partition(begin, end);
    if (mid == kth) {
      return;
    }
    if (kth < mid) {
      end = mid;
    } else {
      begin = mid + 1;
    }
  }
}

#endif
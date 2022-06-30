#ifndef CONTEST1_HEAP_H
#define CONTEST1_HEAP_H

template <class T>
void Swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <class T>
void PushHeap(T* begin, T* end) {
  int size = end - begin - 1;
  if ((-1 < (size - 1) / 2) && begin[(size - 1) / 2] < begin[size]) {
    Swap(begin[(size - 1) / 2], begin[size]);
    PushHeap(begin, &begin[(size - 1) / 2] + 1);
  }
}

template <class T>
void PopHeap(T* begin, T* end) {
  int size = end - begin - 1;
  Swap(begin[0], begin[size]);
  int index = 0;
  end--;
  while (2 * index + 1 < size) {
    int largest = 2 * index + 1;
    int right = 2 * index + 2;
    if ((begin[largest] < begin[right]) && (right < size)) {
      largest = right;
    }
    if (begin[index] < begin[largest]) {
      Swap(begin[largest], begin[index]);
      index = largest;
    } else {
      break;
    }
  }
}

#endif
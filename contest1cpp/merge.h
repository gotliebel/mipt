#ifndef CONTEST1_MERGE_H
#define CONTEST1_MERGE_H

template <class T, class U, class V>
void Merge(T *first_begin, T *first_end, U *second_begin, U *second_end, V *out) {
  int first_index = 0;
  int second_index = 0;
  while ((first_index + first_begin < first_end) && (second_index + second_begin < second_end)) {
    if (first_begin[first_index] < second_begin[second_index]) {
      out[first_index + second_index] = first_begin[first_index];
      first_index++;
    } else {
      out[first_index + second_index] = second_begin[second_index];
      second_index++;
    }
  }
  while (first_index + first_begin < first_end) {
    out[first_index + second_index] = first_begin[first_index];
    first_index++;
  }
  while (second_index + second_begin < second_end) {
    out[first_index + second_index] = second_begin[second_index];
    second_index++;
  }
}

#endif
/*#include <iostream>
#include <cstring>
#include <cmath>

class BigInteger {
  int array_[2000]{};
  static const int kKBase = 1e9;
  int size_ = 1;

 public:
  BigInteger() = default;
  BigInteger(char *str);  // NOLINT
  friend std::ostream &operator<<(std::ostream &os, BigInteger &number);
  friend std::istream &operator>>(std::istream &is, BigInteger &number);
  friend BigInteger operator-(BigInteger first, BigInteger second);
};
BigInteger::BigInteger(char *str) {
  size_t length = strlen(str);
  size_t counter_digits = 0;
  size_t index = 0;
  for (int i = length - 1; i >= 0; --i) {
    if (counter_digits == 9) {
      index++;
      counter_digits = 0;
      size_++;
    }
    array_[index] += (str[i] - '0') * pow(10, counter_digits);
    counter_digits++;
  }
}

std::ostream &operator<<(std::ostream &os, BigInteger &number) {
  os << number.array_[number.size_ - 1];
  for (int i = number.size_ - 2; i >= 0; --i) {
    int j = 0;
    for (; j < 10; ++j) {
      int degree_ten = pow(10, j);
      if (number.array_[i] / degree_ten == 0) {
        break;
      }
    }
    while ((9 - j) > 0) {
      os << '0';
      j++;
    }
    if (number.array_[i]) {
      os << number.array_[i];
    }
  }
  return os;
}
std::istream &operator>>(std::istream &is, BigInteger &number) {
  const int k_size = 30001;
  char str[k_size]{};
  is >> str;
  number = BigInteger(str);
  return is;
}
BigInteger operator-(BigInteger first, BigInteger second) {
  BigInteger final;
  final.size_ = first.size_;
  for (int i = 0; i < first.size_; ++i) {
    final.array_[i] = first.array_[i] - second.array_[i];
    if (final.array_[i] < 0) {
      first.array_[i + 1]--;
      final.array_[i] += BigInteger::kKBase;
    }
  }
  for (int i = final.size_ - 1; i >= 0; --i) {
    if (final.array_[i] == 0) {
      final.size_--;
    } else {
      break;
    }
  }
  if (final.size_ == 0) {
    final.size_ = 1;
  }
  return final;
}

int main() {
  BigInteger a;
  BigInteger b;
  std::cin >> a;
  std::cin >> b;
  BigInteger c;
  c = a - b;
  std::cout << c;
  return 0;
}*/
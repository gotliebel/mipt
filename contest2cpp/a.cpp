/*#include <cmath>
#include <iomanip>
#include <iostream>

class Vector {
 public:
  Vector() = default;
  Vector(const int& x1, const int& y1, const int& x2, const int& y2) : x_(x2 - x1), y_(y2 - y1) {};
  int ScalarMultiply(const Vector& vector) const {
    return x_ * vector.x_ + y_ * vector.y_;
  }
  int VectorMultiply(const Vector& vector) const {
    return x_ * vector.y_ - vector.x_ * y_;
  }
  double Length() const {
    return sqrt(x_ * x_ + y_ * y_);
  }
  friend Vector operator+(const Vector& v1, const Vector& v2);
  friend std::istream& operator>>(std::istream& is, Vector& vector);
  friend std::ostream& operator<<(std::ostream& os, const Vector& vector);

 private:
  int x_;
  int y_;
};
std::ostream& operator<<(std::ostream& os, const Vector& vector) {
  os << vector.x_ << " " << vector.y_ << "\n";
  return os;
}
std::istream& operator>>(std::istream& is, Vector& vector) {
  int x1, y1, x2, y2;
  is >> x1 >> y1 >> x2 >> y2;
  vector = Vector(x1, y1, x2, y2);
  return is;
}
Vector operator+(const Vector& v1, const Vector& v2) {
  Vector final{};
  final.x_ = v1.x_ + v2.x_;
  final.y_ = v1.y_ + v2.y_;
  return final;
}

int main() {
  Vector vector_first{};
  Vector vector_second{};
  std::cin >> vector_first;
  std::cin >> vector_second;
  std::cout << std::setprecision(7) << vector_first.Length() << " ";
  std::cout << std::setprecision(7) << vector_second.Length() << "\n";
  Vector vector_sum = vector_first + vector_second;
  std::cout << vector_sum;
  std::cout << vector_first.ScalarMultiply(vector_second) << " " << vector_first.VectorMultiply(vector_second) << "\n";
  std::cout << std::setprecision(7) << abs(vector_first.VectorMultiply(vector_second)) / 2.0;
  return 0;
}*/
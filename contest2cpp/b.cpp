/*#include <cmath>
#include <iomanip>
#include <iostream>

class Point {

 public:
  double x_;
  double y_;

  Point() = default;
};
class Line {

 public:
  double a_;
  double b_;
  double c_;

  Line() = default;

  Line(const double& a, const double& b, const double& c) : a_(a), b_(b), c_(c){};
  void CrossPointFinding(const Line &line) const {
    if (-c_ * line.b_ + line.c_ * b_ == 0) {
      std::cout << 0 << " ";
    } else {
      std::cout << std::setprecision(9) << (-c_ * line.b_ + line.c_ * b_) / (a_ * line.b_ - line.a_ * b_) << " ";
    }
    if (-a_ * line.c_ + c_ * line.a_ == 0) {
      std::cout << 0;
    } else {
      std::cout << std::setprecision(9) << (-a_ * line.c_ + c_ * line.a_) / (a_ * line.b_ - line.a_ * b_);
    }
  }
  void PrintGuideVector() const {
    if (a_ == 0) {
      std::cout << b_ << " " << a_ << "\n";
    } else {
      std::cout << b_ << " " << -a_ << "\n";
    }
  }
  void FindPoint(Point &point) const {
    if (b_ != 0) {
      point.x_ = 0;
      point.y_ = -c_ / b_;
    } else {
      point.y_ = 0;
      point.x_ = -c_ / a_;
    }
  }
};
class Vector {

 public:
  double x_;
  double y_;

  Vector() = default;

  Vector(const Point& a, const Point& b) : x_(b.x_ - a.x_), y_(b.y_ - a.y_){};
  double VectorMultiply(const Vector &vector) const {
    return x_ * vector.y_ - vector.x_ * y_;
  }
  double Length() const {
    return sqrt(x_ * x_ + y_ * y_);
  }
  void SetCoordinatesFromLine(const Line &line) {
    if (line.a_ == 0) {
      y_ = 0;
    } else {
      y_ = -line.a_;
    }
    x_ = line.b_;
  }
};

std::istream &operator>>(std::istream &is, Line &line) {
  double a, b, c;
  is >> a >> b >> c;
  line = Line(a, b, c);
  return is;
}

int main() {
  Line l1{};
  std::cin >> l1;
  Line l2{};
  std::cin >> l2;
  Vector first_vector{};
  Vector second_vector{};
  l1.PrintGuideVector();
  l2.PrintGuideVector();
  first_vector.SetCoordinatesFromLine(l1);
  second_vector.SetCoordinatesFromLine(l2);
  if (first_vector.VectorMultiply(second_vector) != 0) {
    l1.CrossPointFinding(l2);
  } else {
    Point point_first{};
    l1.FindPoint(point_first);
    Point point_second{};
    l2.FindPoint(point_second);
    Vector vector = Vector(point_first, point_second);
    if (vector.VectorMultiply(first_vector) != 0) {
      std::cout << std::setprecision(9) << std::abs(vector.VectorMultiply(first_vector)) / (first_vector.Length());
    } else {
      std::cout << 0;
    }
  }
  return 0;
}*/
/*#include <iostream>

class Segment;
class Point {
 public:
  int64_t x_;
  int64_t y_;

  Point() = default;
  Point(const int64_t& x, const int64_t& y) : x_(x), y_(y){};
};
class Vector {

 public:
  Vector(const Point& a, const Point& b) : begin_(a), end_(b){};
  Vector() = default;
  explicit Vector(const Segment& segment);
  int64_t VectorMultiply(const Vector& vector) const {
    return (end_.x_ - begin_.x_) * (vector.end_.y_ - vector.begin_.y_) -
        (vector.end_.x_ - vector.begin_.x_) * (end_.y_ - begin_.y_);
  }
  int64_t ScalarMultiply(const Vector& vector) const {
    return (end_.x_ - begin_.x_) * (vector.end_.x_ - vector.begin_.x_) +
        (end_.y_ - begin_.y_) * (vector.end_.y_ - vector.begin_.y_);
  }

 private:
  Point begin_;
  Point end_;
};
class Segment {

 public:
  Point begin_;
  Point end_;
  Segment() = default;
  Segment(const Point& first, const Point& second) : begin_(first), end_(second){};
  bool EndsAreOnDifferentSidesAndNonCollinear(const Segment& segment) const;
  bool IsCollinear(const Segment& segment) const;
  bool OnePointContains(const Segment& segment) const;
};
Vector::Vector(const Segment& segment) : begin_(segment.begin_), end_(segment.end_) {
}

bool Segment::EndsAreOnDifferentSidesAndNonCollinear(const Segment& segment) const {
  return (Vector(*this).VectorMultiply(Vector(begin_, segment.end_)) *
      Vector(*this).VectorMultiply(Vector(begin_, segment.begin_)) <
      0 &&
      Vector(segment).VectorMultiply(Vector(segment.begin_, begin_)) *
          Vector(segment).VectorMultiply(Vector(segment.begin_, end_)) <
          0);
}
bool Segment::IsCollinear(const Segment& segment) const {
  return (Vector(*this).VectorMultiply(Vector(begin_, segment.end_)) *
      Vector(*this).VectorMultiply(Vector(begin_, segment.begin_)) ==
      0 ||
      Vector(segment).VectorMultiply(Vector(segment.begin_, begin_)) *
          Vector(segment).VectorMultiply(Vector(segment.begin_, end_)) ==
          0);
}
bool Segment::OnePointContains(const Segment& segment) const {
  return ((Vector(*this).VectorMultiply(Vector(begin_, segment.begin_)) == 0 &&
      (Vector(segment.begin_, begin_)).ScalarMultiply(Vector(segment.begin_, end_)) <= 0) ||
      (Vector(*this).VectorMultiply(Vector(begin_, segment.end_)) == 0 &&
          (Vector(segment.end_, begin_)).ScalarMultiply(Vector(segment.end_, end_)) <= 0) ||
      (Vector(segment).VectorMultiply(Vector(begin_, segment.end_)) == 0 &&
          (Vector(begin_, segment.begin_)).ScalarMultiply(Vector(begin_, segment.end_)) <= 0) ||
      (Vector(segment).VectorMultiply(Vector(segment.begin_, end_)) == 0 &&
          (Vector(end_, segment.begin_)).ScalarMultiply(Vector(end_, segment.end_)) <= 0));
}

std::istream& operator>>(std::istream& is, Segment& segment) {
  int x1, y1, x2, y2;
  is >> x1 >> y1 >> x2 >> y2;
  segment = Segment(Point(x1, y1), Point(x2, y2));
  return is;
}
int main() {
  Segment segment_first{};
  Segment segment_second{};
  std::cin >> segment_first >> segment_second;
  if (segment_first.EndsAreOnDifferentSidesAndNonCollinear(segment_second)) {
    std::cout << "YES";
  } else if (segment_first.IsCollinear(segment_second)) {
    if (segment_first.OnePointContains(segment_second)) {
      std::cout << "YES";
    } else {
      std::cout << "NO";
    }
  } else {
    std::cout << "NO";
  }
  return 0;
}*/

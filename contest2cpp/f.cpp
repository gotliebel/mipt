/*#include <cmath>
#include <iomanip>
#include <iostream>

class Segment;
class Point {

 public:
  int64_t x_;
  int64_t y_;
  Point() = default;
  Point(const int64_t& x, const int64_t& y) : x_(x), y_(y){};
  double DistancePointSegment(const Segment& segment) const;
  double DistancePoints(const Point& point) const;
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
  bool CrossingSegments(const Segment& segment) const {
    if (EndsAreOnDifferentSidesAndNonCollinear(segment)) {
      return true;
    }
    if (IsCollinear(segment)) {
      return (OnePointContains(segment));
    }
    return false;
  }
  double DistanceSegments(const Segment& segment) const;
  double DistanceSegmentsPoints(const Segment& segment) const;
};
bool Comp(const double& a, const double& b) {
  if (a == -1) {
    return false;
  }
  if (b == -1) {
    return true;
  }
  if (a == -1 && b == -1) {
    return true;
  }
  if (a <= b) {
    return true;
  }
  return false;
}

double Segment::DistanceSegments(const Segment& segment) const {
  double dist_first = (*this).begin_.DistancePointSegment(segment);
  double dist_second = (*this).end_.DistancePointSegment(segment);
  double dist_third = segment.begin_.DistancePointSegment(*this);
  double dist_fourth = segment.end_.DistancePointSegment(*this);
  double min_dist = std::min(std::min(dist_first, dist_second, Comp), std::min(dist_third, dist_fourth, Comp), Comp);
  return min_dist;
}
double Segment::DistanceSegmentsPoints(const Segment& segment) const {
  double dist_first = (*this).begin_.DistancePoints(segment.begin_);
  double dist_second = (*this).end_.DistancePoints(segment.begin_);
  double dist_third = (*this).begin_.DistancePoints(segment.end_);
  double dist_fourth = (*this).end_.DistancePoints(segment.end_);
  double min_dist = std::min(std::min(dist_first, dist_second), std::min(dist_third, dist_fourth));
  return min_dist;
}
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
double Point::DistancePointSegment(const Segment& segment) const {
  if (((x_ - segment.begin_.x_) * (segment.end_.x_ - segment.begin_.x_) +
      (y_ - segment.begin_.y_) * (segment.end_.y_ - segment.begin_.y_) >=
      0) &&
      ((x_ - segment.end_.x_) * (segment.begin_.x_ - segment.end_.x_) +
          (y_ - segment.end_.y_) * (segment.begin_.y_ - segment.end_.y_)) >= 0) {
    return std::abs((segment.end_.x_ - segment.begin_.x_) * (y_ - segment.begin_.y_) -
        (segment.end_.y_ - segment.begin_.y_) * (x_ - segment.begin_.x_)) /
        sqrt((segment.end_.x_ - segment.begin_.x_) * (segment.end_.x_ - segment.begin_.x_) +
            (segment.end_.y_ - segment.begin_.y_) * (segment.end_.y_ - segment.begin_.y_));
  }
  return -1;
}
double Point::DistancePoints(const Point& point) const {
  return (sqrt((x_ - point.x_) * (x_ - point.x_) + (y_ - point.y_) * (y_ - point.y_)));
}
std::istream& operator>>(std::istream& is, Segment& segment) {
  int64_t x1, y1, x2, y2;
  is >> x1 >> y1 >> x2 >> y2;
  segment = Segment(Point(x1, y1), Point(x2, y2));
  return is;
}
int main() {
  Segment segment_first{};
  Segment segment_second{};
  std::cin >> segment_first >> segment_second;
  if (segment_first.CrossingSegments(segment_second)) {
    std::cout << 0;
  } else {
    double min_dist = segment_first.DistanceSegments(segment_second);
    if (min_dist == -1) {
      min_dist = segment_first.DistanceSegmentsPoints(segment_second);
    }
    std::cout << std::setprecision(7) << min_dist;
  }
  return 0;
}*/
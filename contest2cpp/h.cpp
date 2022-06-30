/*#include <iostream>
#include <vector>

class Line;
class Ray;
class Segment;
class Point {
 public:
  int64_t x_;
  int64_t y_;
  Point() = default;
  Point(const int64_t& x, const int64_t& y) : x_(x), y_(y){};
  bool BelongsLine(const Line& line) const;
  bool BelongsRay(const Ray& ray) const;
  bool BelongsSegment(const Segment& segment) const;
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


class Line {
 public:
  Point begin_;
  Point end_;
  Line() = default;
  Line(const Point& a, const Point& b) : begin_(a), end_(b){};
};
class Ray {
 public:
  Point begin_;
  Point end_;
  Ray() = default;
  Ray(const Point& a, const Point& b) : begin_(a), end_(b){};
};
class Segment {
 public:
  Point begin_;
  Point end_;
  Segment() = default;
  Segment(const Point& a, const Point& b) : begin_(a), end_(b){};
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
};
Vector::Vector(const Segment& segment) : begin_(segment.begin_), end_(segment.end_) {
}
bool Point::BelongsLine(const Line& line) const {
  return x_ * (line.end_.y_ - line.begin_.y_) - line.begin_.x_ * (line.end_.y_ - line.begin_.y_) - y_ * (line.end_.x_ - line.begin_.x_) + line.begin_.y_ * (line.end_.x_ - line.begin_.x_) == 0;
}
bool Point::BelongsRay(const Ray& ray) const {
  return (this->BelongsLine(Line(ray.begin_, ray.end_)) && ((ray.begin_.x_ - x_) * (ray.end_.x_ - ray.begin_.x_) + (ray.begin_.y_ - y_) * (ray.end_.y_ - ray.begin_.y_) <= 0));
}
bool Point::BelongsSegment(const Segment& segment) const {
  return (this->BelongsRay(Ray(segment.begin_, segment.end_)) && (segment.end_.x_ - x_) * (segment.end_.x_ - segment.begin_.x_) + (segment.end_.y_ - y_) * (segment.end_.y_ - segment.begin_.y_) >= 0);
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

class Polygon {

 public:
  Polygon() = default;
  explicit Polygon(int number_points) {
    points_.resize(number_points);
  }
  Point GetPoint(unsigned int index) const {
    return points_[index];
  }
  friend std::istream& operator>>(std::istream& is, Polygon& polygon);
  unsigned int GetSize() const {
    return points_.size();
  }

 private:
  std::vector<Point> points_;

};
std::istream& operator>>(std::istream& is, Polygon& polygon) {
  int x = 0;
  int y = 0;
  for (auto & point : polygon.points_) {
    is >> x >> y;
    point = Point(x, y);
  }
  return is;
}


int main() {
  int number_points = 0;
  std::cin >> number_points;
  int64_t x, y;
  std::cin >> x >> y;
  Polygon polygon(number_points);
  std::cin >> polygon;
  Point check_point(x, y);
  const int max_coordinate = 100000000;
  Point largest_point(max_coordinate, check_point.y_ + 1);
  bool is_in_polygon = false;
  int counter = 0;
  Segment segment(check_point, largest_point);
  for (int i = 0; i < polygon.GetSize() - 1; ++i) {
    if (check_point.BelongsSegment(Segment(polygon.GetPoint(i), polygon.GetPoint(i + 1)))) {
      is_in_polygon = true;
    }
    if (segment.CrossingSegments(Segment(polygon.GetPoint(i), polygon.GetPoint(i + 1)))) {
      counter++;
    }
  }
  if (segment.CrossingSegments(Segment(polygon.GetPoint(polygon.GetSize() - 1), polygon.GetPoint(0)))) {
    counter++;
  }
  if (is_in_polygon) {
    std::cout << "YES";
  } else {
    if (counter % 2 != 0) {
      std::cout << "YES";
    } else {
      std::cout << "NO";
    }
  }
  return 0;
}*/
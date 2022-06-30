/*#include <cmath>
#include <iomanip>
#include <iostream>

class Line;
class Ray;
class Segment;

class Point {
 public:
  int x_;
  int y_;
  Point() = default;
  Point(const int &x, const int &y) : x_(x), y_(y) {};
  double DistanceLine(const Line &line) const;
  double DistanceRay(const Ray &ray) const;
  double DistanceSegment(const Segment &segment) const;
};
std::istream &operator>>(std::istream &is, Point &point) {
  int x, y;
  is >> x >> y;
  point = Point(x, y);
  return is;
}
class Line {
 public:
  Point a_;
  Point b_;
  Line() = default;
  Line(const Point &a, const Point &b) : a_(a), b_(b) {};
};
class Ray {
 public:
  Point a_;
  Point b_;
  Ray() = default;
  Ray(const Point &a, const Point &b) : a_(a), b_(b) {};
};
class Segment {
 public:
  Point a_;
  Point b_;
  Segment() = default;
  Segment(const Point &a, const Point &b) : a_(a), b_(b) {};
};

double Point::DistanceLine(const Line &line) const {
  if ((line.b_.x_ - line.a_.x_) * (y_ - line.a_.y_) - (line.b_.y_ - line.a_.y_) * (x_ - line.a_.x_) == 0) {
    return 0;
  }
  return abs((line.b_.x_ - line.a_.x_) * (y_ - line.a_.y_) - (line.b_.y_ - line.a_.y_) * (x_ - line.a_.x_)) /
      sqrt((line.b_.x_ - line.a_.x_) * (line.b_.x_ - line.a_.x_)
               + (line.b_.y_ - line.a_.y_) * (line.b_.y_ - line.a_.y_));
}
double Point::DistanceRay(const Ray &ray) const {
  if ((x_ - ray.a_.x_) * (ray.b_.x_ - ray.a_.x_) + (y_ - ray.a_.y_) * (ray.b_.y_ - ray.a_.y_) >= 0) {
    return abs((ray.b_.x_ - ray.a_.x_) * (y_ - ray.a_.y_) - (ray.b_.y_ - ray.a_.y_) * (x_ - ray.a_.x_)) /
        sqrt((ray.b_.x_ - ray.a_.x_) * (ray.b_.x_ - ray.a_.x_) + (ray.b_.y_ - ray.a_.y_) * (ray.b_.y_ - ray.a_.y_));
  }

  return sqrt((x_ - ray.a_.x_) * (x_ - ray.a_.x_) + (y_ - ray.a_.y_) * (y_ - ray.a_.y_));
}
double Point::DistanceSegment(const Segment &segment) const {
  if (((x_ - segment.a_.x_) * (segment.b_.x_ - segment.a_.x_) + (y_ - segment.a_.y_) * (segment.b_.y_ - segment.a_.y_)
      >= 0) &&
      ((x_ - segment.b_.x_) * (segment.a_.x_ - segment.b_.x_) + (y_ - segment.b_.y_) * (segment.a_.y_ - segment.b_.y_))
          >= 0) {
    return abs((segment.b_.x_ - segment.a_.x_) * (y_ - segment.a_.y_)
                   - (segment.b_.y_ - segment.a_.y_) * (x_ - segment.a_.x_)) /
        sqrt((segment.b_.x_ - segment.a_.x_) * (segment.b_.x_ - segment.a_.x_)
                 + (segment.b_.y_ - segment.a_.y_) * (segment.b_.y_ - segment.a_.y_));
  }
  return sqrt(std::min((x_ - segment.a_.x_) * (x_ - segment.a_.x_) + (y_ - segment.a_.y_) * (y_ - segment.a_.y_),
                       (x_ - segment.b_.x_) * (x_ - segment.b_.x_) + (y_ - segment.b_.y_) * (y_ - segment.b_.y_)));
}
int main() {
  Point c{}, a{}, b{};
  std::cin >> c;
  std::cin >> a >> b;
  Line line(a, b);
  Ray ray(a, b);
  Segment segment(a, b);
  std::cout << std::setprecision(7) << c.DistanceLine(line) << "\n";
  std::cout << std::setprecision(7) << c.DistanceRay(ray) << "\n";
  std::cout << std::setprecision(7) << c.DistanceSegment(segment);
  return 0;
}*/
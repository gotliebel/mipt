/*#include <iostream>

class Line;
class Ray;
class Segment;

class Point {

 public:
  int x_;
  int y_;
  Point() = default;
  Point(const int& x, const int& y) : x_(x), y_(y) {};
  bool BelongsLine(const Line& line) const;
  bool BelongsRay(const Ray& ray) const;
  bool BelongsSegment(const Segment& segment) const;
};
std::istream& operator>>(std::istream& is, Point& point) {
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
  Line(const Point& a, const Point& b) : a_(a), b_(b){};
};
class Ray {
 public:
  Point a_;
  Point b_;
  Ray() = default;
  Ray(const Point& a, const Point& b) : a_(a), b_(b){};
};
class Segment {
 public:
  Point a_;
  Point b_;
  Segment() = default;
  Segment(const Point& a, const Point& b) : a_(a), b_(b){};
};
bool Point::BelongsLine(const Line& line) const {
  return x_ * (line.b_.y_ - line.a_.y_) - line.a_.x_ * (line.b_.y_ - line.a_.y_) - y_ * (line.b_.x_ - line.a_.x_) + line.a_.y_ * (line.b_.x_ - line.a_.x_) == 0;
}
bool Point::BelongsRay(const Ray& ray) const {
  return (this->BelongsLine(Line(ray.a_, ray.b_)) && ((ray.a_.x_ - x_) * (ray.b_.x_ - ray.a_.x_) + (ray.a_.y_ - y_) * (ray.b_.y_ - ray.a_.y_) <= 0));
}
bool Point::BelongsSegment(const Segment& segment) const {
  return (this->BelongsRay(Ray(segment.a_, segment.b_)) && (segment.b_.x_ - x_) * (segment.b_.x_ - segment.a_.x_) + (segment.b_.y_ - y_) * (segment.b_.y_ - segment.a_.y_) >= 0);
}
int main() {
  Point c{}, a{}, b{};
  std::cin >> c;
  std::cin >> a;
  std::cin >> b;
  Line line(a, b);
  Ray ray(a, b);
  Segment segment(a, b);
  if (c.BelongsLine(line)) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
  if (c.BelongsRay(ray)) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
  if (c.BelongsSegment(segment)) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}*/
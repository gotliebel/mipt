/*#include <iostream>
#include <string>
#include <vector>

enum Sign {
  Zero,
  Positive,
  Negative
};
class Point {

 public:
  int64_t x_;
  int64_t y_;
  Point() = default;
  Point(const int64_t& x,const int64_t& y) : x_(x), y_(y){};
  Sign SignVectorMultiply(const Point& b, const Point& c) const {
    if ((b.x_ - x_) * (c.y_ - b.y_) - (c.x_ - b.x_) * (b.y_ - y_) > 0) {
      return Positive;
    }
    if ((b.x_ - x_) * (c.y_ - b.y_) - (c.x_ - b.x_) * (b.y_ - y_) == 0) {
      return Zero;
    }
    return Negative;
  }
};
class Polygon {

 public:
  Polygon() = default;
  bool IsConvex() const {
    Sign sign = points_[0].SignVectorMultiply(points_[1], points_[2]);
    bool incorrect_polygon = false;
    unsigned int counter = 1;
    if (sign == Zero) {
      while (sign == Zero && counter < points_.size() - 2) {
        sign = points_[counter].SignVectorMultiply(points_[counter + 1], points_[counter + 2]);
        counter++;
      }
    }
    for (int i = counter; i < points_.size() - 2; ++i) {
      if (points_[i].SignVectorMultiply(points_[i + 1], points_[i + 2]) != sign &&
          points_[i].SignVectorMultiply(points_[i + 1], points_[i + 2]) != Zero) {
        incorrect_polygon = true;
      }
    }
    if (points_[points_.size() - 2].SignVectorMultiply(points_[points_.size() - 1], points_[0]) != sign &&
        points_[points_.size() - 2].SignVectorMultiply(points_[points_.size() - 1], points_[0]) != Zero) {
      incorrect_polygon = true;
    }
    if (points_[points_.size() - 1].SignVectorMultiply(points_[0], points_[1]) != sign &&
        points_[points_.size() - 1].SignVectorMultiply(points_[0], points_[1]) != Zero) {
      incorrect_polygon = true;
    }
    if (incorrect_polygon) {
      return false;
    }
    if (sign == Zero) {
      return false;
    }
    return true;
  }
  friend std::istream& operator>>(std::istream& is, Polygon& polygon);
 private:
  std::vector<Point> points_;
};
std::istream& operator>>(std::istream& is, Polygon& polygon) {
  int number_points = 0;
  is >> number_points;
  int x = 0;
  int y = 0;
  polygon.points_.resize(number_points);
  for (int i = 0; i < number_points; ++i) {
    is >> x >> y;
    polygon.points_[i] = Point(x, y);
  }
  return is;
}

int main() {
  Polygon polygon{};
  std::cin >> polygon;
  if (polygon.IsConvex()) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}*/
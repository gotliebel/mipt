/*#include <iomanip>
#include <iostream>
#include <vector>

class Point {

 public:
  int64_t x_;
  int64_t y_;
  Point() = default;
  Point(const int64_t& x, const int64_t& y) : x_(x), y_(y){};
};
class Polygon {
 public:
  Polygon() = default;
  double Area() {
    double square = 0;
    for (unsigned int i = 0; i < points_.size() - 1; ++i) {
      square += (points_[i].x_ + points_[i + 1].x_) * (points_[i + 1].y_ - points_[i].y_);
    }
    square += (points_[0].x_ + points_[points_.size() - 1].x_) * (points_[0].y_ - points_[points_.size() - 1].y_);
    return square;
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
  std::cout << std::fixed << std::setprecision(15) << std::abs(polygon.Area()) / 2.0;
  return 0;
}*/
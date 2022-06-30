/*#include <algorithm>
#include <iostream>
#include <vector>

class Vector {
 public:
  Vector() = default;
  Vector(const int64_t &x, const int64_t &y) : x_(x), y_(y) {};
  int64_t VectorMultiply(const Vector &vector) const {
    return x_ * vector.y_ - vector.x_ * y_;
  }
 private:
  int64_t x_;
  int64_t y_;
};

class Point {
 public:
  int64_t x_;
  int64_t y_;

  Point() = default;
  Point(const int &x, const int &y) : x_(x), y_(y) {};
};
Vector operator-(const Point &first, const Point &second) {
  return Vector(first.x_ - second.x_, first.y_ - second.y_);
}
class Polygon {
 public:
  std::vector<Point> points_;
  int size_hull;
  Polygon() = default;
  Point &GetPoint(int index) {
    return points_[index];
  }
  double Area() {
    double area = 0;
    for (unsigned int i = 0; i < points_.size() - 1; ++i) {
      area += (points_[i].x_ + points_[i + 1].x_) * (points_[i + 1].y_ - points_[i].y_);
    }
    area += (points_[0].x_ + points_[points_.size() - 1].x_) * (points_[0].y_ - points_[points_.size() - 1].y_);
    return area;
  }
  Polygon ConvexHull() {
    Polygon final_polygon{};
    final_polygon.points_.push_back(points_[0]);
    final_polygon.points_.push_back(points_[1]);
    final_polygon.size_hull = 2;
    for (int i = 2; i < points_.size(); ++i) {
      while (final_polygon.points_.size() >= 2 && (final_polygon.points_[final_polygon.points_.size() - 1]
          - final_polygon.points_[final_polygon.points_.size() - 2]).VectorMultiply(
          GetPoint(i) - final_polygon.points_[final_polygon.points_.size() - 1]) <= 0) {
        final_polygon.points_.pop_back();
        final_polygon.size_hull--;
      }
      final_polygon.points_.push_back(points_[i]);
      final_polygon.size_hull++;
    }
    if ((final_polygon.points_[0].x_ == final_polygon.points_[final_polygon.size_hull - 1].x_
        && final_polygon.points_[final_polygon.size_hull - 1].x_
            == final_polygon.points_[final_polygon.size_hull - 2].x_) ||
        (final_polygon.points_[0].y_ == final_polygon.points_[final_polygon.size_hull - 1].y_
            && final_polygon.points_[final_polygon.size_hull - 1].y_
                == final_polygon.points_[final_polygon.size_hull - 2].y_)) {
      final_polygon.points_.pop_back();
      final_polygon.size_hull--;
    }
    return final_polygon;
  }

};
std::istream &operator>>(std::istream &is, Polygon &polygon) {
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
std::ostream &operator<<(std::ostream &os, const Polygon &polygon) {
  os << polygon.points_[0].x_ << " " << polygon.points_[0].y_ << "\n";
  for (unsigned int i = polygon.points_.size() - 1; i > 0; --i) {
    os << polygon.points_[i].x_ << " " << polygon.points_[i].y_ << "\n";
  }
  return os;
}

int main() {
  Polygon polygon{};
  std::cin >> polygon;
  for (int i = 1; i < polygon.points_.size(); ++i) {
    if (polygon.GetPoint(i).x_ < polygon.GetPoint(0).x_
        || (polygon.GetPoint(i).x_ == polygon.GetPoint(0).x_ && polygon.GetPoint(i).y_ < polygon.GetPoint(0).y_)) {
      std::swap(polygon.GetPoint(i), polygon.GetPoint(0));
    }
  }
  std::sort(polygon.points_.begin() + 1, polygon.points_.end(), [&polygon](Point a, Point b) {
    if ((a.x_ - polygon.GetPoint(0).x_) * (b.y_ - polygon.GetPoint(0).y_)
        - (a.y_ - polygon.GetPoint(0).y_) * (b.x_ - polygon.GetPoint(0).x_) > 0) {
      return true;
    }
    if ((a.x_ - polygon.GetPoint(0).x_) * (b.y_ - polygon.GetPoint(0).y_) -
        (a.y_ - polygon.GetPoint(0).y_) * (b.x_ - polygon.GetPoint(0).x_) !=
        0) {
      return false;
    }
    if ((polygon.GetPoint(0).x_ - a.x_) * (polygon.GetPoint(0).x_ - a.x_) +
        (polygon.GetPoint(0).y_ - a.y_) * (polygon.GetPoint(0).y_ - a.y_) -
        (polygon.GetPoint(0).x_ - b.x_) * (polygon.GetPoint(0).x_ - b.x_) +
        (polygon.GetPoint(0).y_ - b.y_) * (polygon.GetPoint(0).y_ - b.y_) <
        0) {
      return true;
    }
    return false;
  });

  Polygon final_polygon = polygon.ConvexHull();
  std::cout << final_polygon.points_.size() << "\n";
  std::cout << final_polygon;
  std::cout << std::abs(final_polygon.Area()) / 2.0;
  return 0;
}*/
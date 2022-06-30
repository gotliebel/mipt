/*#include <iostream>


class Time {
  size_t day_;
  size_t month_;
  size_t year_;
  bool LeapYear();
  public:
    void SetDay(size_t day);
    void SetDate(size_t day, size_t month, size_t year);
};
void SetDate(size_t day, size_t month, size_t year) {

}
bool Time::LeapYear() {
  return year_ % 4 == 0 && year_ % 100 != 0 || year_ % 400 == 0;
}
void Time::SetDay(size_t day) {
  if (day > 31 || day == 0) {
    return;
  }
  if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {
    day_ = day;
    return;
  }
  if (month_ == 2) {
    if (LeapYear()) {
      if (day <= 29) {
        day_ = day;
        return;
      } else {
        return;
      }
    } else {
      if (day <= 28) {
        day_ = day;
        return;
      } else {
        return;
      }
    }
  }
  day_= day;
}*/
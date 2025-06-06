
/// File: element.cpp
#include "element.h"
// constructor - khởi tạo
element::element() {
  this->data = 0;
  this->pointer = nullptr;
}
element::element(int data) {
  this->data = data;
  this->pointer = nullptr;
}
// destructor - hàm huỷ - giải phóng bộ nhớ
element::~element() {
  // dtor
}


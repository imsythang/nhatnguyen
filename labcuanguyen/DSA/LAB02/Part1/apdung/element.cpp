
/// File: Element.cpp
#include "Element.h"
// constructor - khởi tạo
Element::Element() {
  this->data = 0;
  this->pointer = nullptr;
}
Element::Element(int data) {
  this->data = data;
  this->pointer = nullptr;
}
// destructor - hàm huỷ - giải phóng bộ nhớ
Element::~Element() {
  // dtor
}


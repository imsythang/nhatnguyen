#include "polynominal.h"
#include <iostream>
#include <cmath>
using namespace std;
Polynominal::Polynominal() {
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}

Polynominal::~Polynominal() {
    // Destructor
}
void Polynominal::AddTermTail(term* newTerm) {
  // Check exp
  // Đây là danh sách giảm dần theo số mũ
  // x^3 + 3x^2 + 2x + 1
  // newTerm = -2x^2
  // x^3 + 3x^2 - 2x^2 + 2x + 1
  // x^3 + x^2 + 2x + 1
    if (this->head == nullptr) {
        this->head = this->tail = newTerm;
    } else {
        this->tail->setNext(newTerm);
        this->tail = newTerm;
    }
    this->nNum++;
}

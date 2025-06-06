#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "term.h"

class Polynominal {
private:
  term* head; // con trỏ đến phần tử đầu tiên
  term* tail; // con trỏ đến phần tử cuối cùng
  int nNum; // số lượng các hệ số trong đa thức
public:
  Polynominal();
  ~Polynominal();
  void AddTermTail(term*);
  void Print() const;
  int evaluate(int x);
};

#endif // POLYNOMIAL_H

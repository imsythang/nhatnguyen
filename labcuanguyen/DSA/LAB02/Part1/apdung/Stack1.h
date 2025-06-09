#ifndef STACK1_H
#define STACK1_H
#include "linkedList.h"
// Thêm đầu xóa đầu
using namespace std;
#include <iostream>
class Stack1 {
private:
  int nNum; // Số lượng phần tử trong stack
  LinkedList *linkedlist;

public:
  Stack1();
  virtual ~Stack1();
  void PushStack(int);
  int PopStack();
  void printStack();
  bool isEmpty() const;
  bool isEmpty();
};

#endif //STACK1_H

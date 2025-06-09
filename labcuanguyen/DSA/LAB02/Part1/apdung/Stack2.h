
#ifndef STACK2_H
#define STACK2_H
#include "linkedList.h"
#include <iostream>
using namespace std;
// Thêm cuối xóa cuối
class Stack2 {
private:
  int nNum;
  LinkedList *linkedlist;

public:
  Stack2();
  virtual ~Stack2();
  void PushStack(int);
  int PopStack();
  void printStack();
  bool isEmpty() const;
  bool isEmpty();
};

#endif // STACK_H2

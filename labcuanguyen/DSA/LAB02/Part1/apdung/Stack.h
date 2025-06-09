#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"
#include <iostream>
using namespace std;

class Stack {
protected:
  int nNum;
  LinkedList *linkedlist;

public:
  Stack();          // Constructor
  virtual ~Stack(); // Destructor

  void printStack();
  bool isEmpty() const;

  virtual void PushStack(int data) = 0;
  virtual int PopStack() = 0;
};

// Stack1 (Thêm đầu, xóa đầu)
class Stack1 : public Stack {
public:
  Stack1();
  void PushStack(int data) override;
  int PopStack() override;
};

// Stack2 (Thêm cuối, xóa cuối)
class Stack2 : public Stack {
public:
  Stack2();
  void PushStack(int data) override;
  int PopStack() override;
};

#endif // STACK_H

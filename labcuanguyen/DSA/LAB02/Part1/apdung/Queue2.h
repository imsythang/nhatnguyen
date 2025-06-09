#ifndef QUEUE2_H
#define QUEUE2_H
#include "LinkedList.h"
#include <iostream>
using namespace std;
// Thêm cuối xóa đầu
class Queue2 {
private:
  int nNum;
  LinkedList *linkedlist;

public:
  Queue2();
  ~Queue2();
  void EnQueue(int);
  int DeQueue();
  void printQueue();
  bool isEmpty();
};

#endif // !QUEUE1_H

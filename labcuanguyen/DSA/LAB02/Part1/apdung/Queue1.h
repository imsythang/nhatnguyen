#ifndef QUEUE1_H
#define QUEUE1_H
#include "LinkedList.h"
#include <iostream>
using namespace std;
// Thêm đầu xóa cuối
class Queue1{
  private:
  int nNum;
  LinkedList* linkedlist;
  public:
  Queue1();
  ~Queue1();
  void EnQueue(int);
  int DeQueue();
  void printQueue();
  bool isEmpty();
};

#endif // !QUEUE1_H




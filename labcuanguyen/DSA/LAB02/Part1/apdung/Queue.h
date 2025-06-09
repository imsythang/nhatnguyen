#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"
#include <iostream>
using namespace std;

// Lớp cơ sở Queue với các phương thức chung
class Queue {
protected:
  int nNum;
  LinkedList *linkedlist;

public:
  Queue();          // Constructor
  virtual ~Queue(); // Destructor

  void printQueue();    // In danh sách
  bool isEmpty() const; // Kiểm tra queue có rỗng không

  // Các phương thức EnQueue và DeQueue sẽ được định nghĩa lại trong các lớp con
  virtual void EnQueue(int data) = 0;
  virtual int DeQueue() = 0;
};

// Queue1 (Thêm đầu, xóa cuối)
class Queue1 : public Queue {
public:
  Queue1();                        // Constructor
  void EnQueue(int data) override; // Chèn phần tử vào đầu
  int DeQueue() override;          // Xóa phần tử từ cuối
};

// Queue2 (Thêm cuối, xóa đầu)
class Queue2 : public Queue {
public:
  Queue2();                        // Constructor
  void EnQueue(int data) override; // Chèn phần tử vào cuối
  int DeQueue() override;          // Xóa phần tử từ đầu
};

#endif // QUEUE_H

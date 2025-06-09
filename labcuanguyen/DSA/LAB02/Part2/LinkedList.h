#ifndef  LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
class LinkedList {
  private:
  Node *head; // Con trỏ đến đầu danh sách liên kết
  Node *tail; // Con trỏ đến cuối danh sách liên kết
  public:
  // Constructor: khởi tạo danh sách liên kết rỗng
  LinkedList();
  // Destructor: giải phóng bộ nhớ của danh sách liên kết
  ~LinkedList();
  void insertFirst();
  void insertLast();
  void deleteFirst();
  void deleteLast();
  bool count() const;
  void printList() const;
}


#endif // ! LINKEDLIST_H

// File: LinkedList.cpp

#include "linkedlist.h"
#include <iostream>
using namespace std;
LinkedList::LinkedList() {
  // ctor
  this->head = nullptr;
  this->tail = nullptr;
  this->nNum = 0;
}

LinkedList::~LinkedList() {
  // dtor
  RemoveAll();
}
void LinkedList::InsertFirst(Element *e) {
  if (this->head == nullptr)
    this->head = this->tail = e;
  else {
    e->Setpointer(this->head); // step 1
    this->head = e;            // step 2
  }
  this->nNum++;
}
void LinkedList::InsertTail(Element *e) {
  if (this->head == nullptr)
    this->head = this->tail = e;
  else {
    this->tail->Setpointer(e); // step 1
    this->tail = e;            // step 2
  }
  this->nNum++;
}
void LinkedList::Travel() {
  Element *p = this->head;
  while (p != nullptr) {
    cout << p->GetData() << "\t";
    p = p->Getpointer();
  }
}
void LinkedList::DeleteFirst() {
  if (this->head == nullptr) {
    return;
  }
  Element *p = this->head;
  this->head = this->head->Getpointer();
  delete p;
  if (this->head == nullptr) {
    this->tail = nullptr;
  }
}
void LinkedList::RemoveAll() {
  // 10p -> 8next -> 9
  // 8 -> 9
  // 9
  // nullptr nullptr
  Element *p = this->head;
  while (p != nullptr) {
    Element *next = p->Getpointer();
    delete p;
    p = next;
  }
  this->head = this->tail = nullptr;
  this->nNum = 0;
}
int LinkedList::SumList() {
  int sum = 0;
  Element *p = this->head;
  while (p != nullptr) {
    sum += p->GetData();
    p = p->Getpointer();
  }
  return sum;
}

int LinkedList::MaxList() {
  if (head == nullptr)
    return -1; // or some sentinel value
  int max = head->GetData();
  Element *p = head->Getpointer();
  while (p != nullptr) {
    if (p->GetData() > max)
      max = p->GetData();
    p = p->Getpointer();
  }
  return max;
}
int LinkedList::CountPrime() {
  int count = 0;
  Element *p = this->head;
  while (p != nullptr) {
    int data = p->GetData();
    if (data < 2) {
      p = p->Getpointer();
      continue;
    }
    bool isPrime = true;
    for (int i = 2; i * i <= data; i++) {
      if (data % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime)
      count++;
    p = p->Getpointer();
  }
  return count;
}
bool LinkedList::InsertAfterP(Element *p, Element *e) {
  if (this->head == nullptr)
    return false; // List is empty
                  // 1 2 p 3 4
                  // 1 2 p e 3 4
                  // 1 2 3 p
                  // 1 2 3 p e
  if (p == nullptr || e == nullptr)
    return false;
  e->Setpointer(p->Getpointer());
  // Set: Chinh sua, get: nhan gia tri
  p->Setpointer(e);
  if (p == this->tail) {
    this->tail = e; // Update tail if p was the last Element
  }
  nNum++;
  return true;
}
void LinkedList::DeleteTail() {
  if (this->head == nullptr) {
    return;
  }
  if (this->head == this->tail) {
    delete this->head;
    this->head = this->tail = nullptr;
    return;
  }
  Element *p = this->head;
  while (p->Getpointer() != this->tail) {
    p = p->Getpointer();
  }
  delete this->tail;
  this->tail = p;
  this->tail->Setpointer(nullptr);
}
bool LinkedList::DeleteElement(Element *e) {
  if (this->head == nullptr || e == nullptr)
    return false;        // List is empty or Element is null
  if (this->head == e) { // If the Element to delete is the head
    DeleteFirst();
    return true;
  }
  // 3head 4p 5 6 7 tail
  // 3 4 6 7
  Element *p = this->head;
  while (p->Getpointer() != nullptr && p->Getpointer() != e) {
    p = p->Getpointer();
  }
  if (p->Getpointer() == nullptr)
    return false; // Element not found
  p->Setpointer(e->Getpointer());
  // p->next = e->next;
  if (e == this->tail) {
    this->tail = p; // Update tail if necessary
  }
  delete e;
  nNum--;
  return true;
}
int LinkedList::CountValueX(int x) {
  int count = 0;
  Element *p = this->head;
  while (p != nullptr) {
    if (p->GetData() == x)
      count++;
    p = p->Getpointer();
  }
  return count;
}
// 3 4 5 6 7 4 8 5
// Nếu data chưa tồn tại -> thêm vào
// Nếu data đã tồn tại -> không thêm vào -> Skip
bool LinkedList::Exist(int x) {
  Element *p = this->head;
  while (p != nullptr) {
    if (p->GetData() == x)
      return true; // Found the value
    p = p->Getpointer();
  }
  return false; // Value not found
}
void LinkedList::InsertTailNotDuplicate(Element *e) {
  if (Exist(e->GetData())) {
    return;
  }
  InsertTail(e);
}
void LinkedList::SplitList(int x, LinkedList &list1, LinkedList &list2) {
  Element *p = this->head;
  while (p != nullptr) {
    if (p->GetData() < x) {
      // 1 3 5 2 4 6
      // x = 5
      Element *newElement = new Element(p->GetData());
      list1.InsertTail(newElement);
    } else {
      Element *newElement = new Element(p->GetData());
      list2.InsertTail(newElement);
    }
    p = p->Getpointer();
  }
}
// an -> a0
// 0 1 2 ... n => (n - 0 + 1) = n + 1

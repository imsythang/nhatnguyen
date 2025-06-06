// File: linkedlist.cpp

#include "linkedlist.h"
#include <iostream>
using namespace std;
linkedlist::linkedlist() {
  // ctor
  this->head = nullptr;
  this->tail = nullptr;
  this->nNum = 0;
}

linkedlist::~linkedlist() {
  // dtor
}
void linkedlist::InsertFirst(element *e) {
  if (this->head == nullptr)
    this->head = this->tail = e;
  else {
    e->Setpointer(this->head); // step 1
    this->head = e;            // step 2
  }
  this->nNum++;
}
void linkedlist::InsertTail(element *e) {
  if (this->head == nullptr)
    this->head = this->tail = e;
  else {
    this->tail->Setpointer(e); // step 1
    this->tail = e;            // step 2
  }
  this->nNum++;
}
void linkedlist::Travel() {
  element *p = this->head;
  while (p != nullptr) {
    cout << p->Getdata() << "\t";
    p = p->Getpointer();
  }
}
bool linkedlist::DeleteFirst() {
  if (this->head == nullptr)
    return false;
  else {
    element *p = this->head;
    this->head = this->head->Getpointer();
    delete p;
    return true;
  }
}
void linkedlist::RemoveAll(){
  // 10p -> 8next -> 9
  // 8 -> 9
  // 9
  // nullptr nullptr
  element* p = this->head;
  while(p != nullptr)
  {
    element* next = p->Getpointer();
    delete p;
    p = next;
  }
  head = tail = nullptr;
  this->nNum = 0;
}
int linkedlist::SumList()
{
  int sum = 0;
  element *p = this->head;
  while (p != nullptr) {
    sum += p->Getdata();
    p = p->Getpointer();
  }
  return sum;
}

int linkedlist::MaxList()
{
  if (head == nullptr) return -1; // or some sentinel value
  int max = head->Getdata();
  element *p = head->Getpointer();
  while (p != nullptr) {
    if (p->Getdata() > max) max = p->Getdata();
    p = p->Getpointer();
  }
  return max;
}
int linkedlist::CountPrime()
{
  int count = 0;
  element *p = this->head;
  while (p != nullptr) {
    int data = p->Getdata();
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
    if (isPrime) count++;
    p = p->Getpointer();
  }
  return count;
}
bool linkedlist::InsertAfterP(element* p, element *e) {
  if (this->head == nullptr) return false; // List is empty
// 1 2 p 3 4
// 1 2 p e 3 4
// 1 2 3 p
// 1 2 3 p e
  if(p == nullptr || e == nullptr) return false;
  e->Setpointer(p->Getpointer());
  // Set: Chinh sua, get: nhan gia tri
  p->Setpointer(e);
  if(p == this->tail) {
    this->tail = e; // Update tail if p was the last element
  }
  nNum++;
  return true;
}
bool linkedlist::DeleteTail()
{
  // 1 2 3p 4tail || delete p; tail =
  // bieens ddos -> next = tail
  // tail = bien do
  if (this->head == nullptr) return false; // List is empty
  if (this->head == this->tail) { // Only one element
    delete this->head;
    this->head = this->tail = nullptr;
  } else {
    element *p = this->head;
    while (p->Getpointer() != this->tail) {
      p = p->Getpointer();
    }
    element* temp = this->tail; // Save the current tail
    this->tail = p;
    this->tail->Setpointer(nullptr);
    delete temp;
  }
  nNum--;
  return true;
}
bool linkedlist::DeleteElement(element *e) {
  if (this->head == nullptr || e == nullptr) return false; // List is empty or element is null
  if (this->head == e) { // If the element to delete is the head
    return DeleteFirst();
  }
  // 3head 4p 5 6 7 tail
  // 3 4 6 7
  element *p = this->head;
  while (p->Getpointer() != nullptr && p->Getpointer() != e) {
    p = p->Getpointer();
  }
  if (p->Getpointer() == nullptr) return false; // Element not found
  p->Setpointer(e->Getpointer());
  // p->next = e->next;
  if (e == this->tail) {
    this->tail = p; // Update tail if necessary
  }
  delete e;
  nNum--;
  return true;
}
int linkedlist::CountValueX(int x) {
  int count = 0;
  element *p = this->head;
  while (p != nullptr) {
    if (p->Getdata() == x) count++;
    p = p->Getpointer();
  }
  return count;
}
// 3 4 5 6 7 4 8 5
// Nếu data chưa tồn tại -> thêm vào
// Nếu data đã tồn tại -> không thêm vào -> Skip
bool linkedlist::Exist(int x) {
  element *p = this->head;
  while (p != nullptr) {
    if (p->Getdata() == x) return true; // Found the value
    p = p->Getpointer();
  }
  return false; // Value not found
}
void linkedlist::InsertTailNotDuplicate(element* e) {
  if(Exist(e->Getdata())) {
    return;
  }
  InsertTail(e);
}
void linkedlist::SplitList(int x, linkedlist& list1, linkedlist& list2) {
  element *p = this->head;
  while (p != nullptr) {
    if (p->Getdata() < x) {
      // 1 3 5 2 4 6
      // x = 5
      element* newElement = new element(p->Getdata());
      list1.InsertTail(newElement);
    } else {
      element* newElement = new element(p->Getdata());
      list2.InsertTail(newElement);
    }
    p = p->Getpointer();
  }
}
// an -> a0
// 0 1 2 ... n => (n - 0 + 1) = n + 1 

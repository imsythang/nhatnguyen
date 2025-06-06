/// File: main.cpp

#include "linkedlist.h"
#include <iostream>
using namespace std;

int main() {
  linkedlist *list_ = new linkedlist();
  element *e;
  e = new element(9);
  list_->InsertTail(e);
  e = new element(10);
  list_->InsertTail(e);
  e = new element(8);
  list_->InsertTail(e);
  list_->Travel();
  // print
  list_->DeleteFirst();
  cout << "\n";
  list_->Travel();
  cout << "\n";
  linkedlist *list2 = new linkedlist();
  element *e1 = new element(1);
  list2->InsertTailNotDuplicate(e1);
  element *e2 = new element(2);
  list2->InsertTailNotDuplicate(e2);
  element *e3 = new element(1);
  list2->InsertTailNotDuplicate(e3);
  list2->Travel();
}

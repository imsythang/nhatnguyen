#include "Stack.h"

Stack::Stack() {
  linkedlist = new LinkedList();
  nNum = 0;
}

Stack::~Stack() { delete linkedlist; }

void Stack::printStack() {
  linkedlist->Travel();
}

bool Stack::isEmpty() const { return (linkedlist->GetHead() == nullptr); }

// Lớp Stack1 (Thêm đầu, xóa đầu)
Stack1::Stack1() : Stack() {}

void Stack1::PushStack(int data) {
  Element *newElement = new Element(data);
  linkedlist->InsertFirst(newElement);
  nNum++;
}

int Stack1::PopStack() {
  if (isEmpty()) {
    cout << "STACK RONG, KHONG LAY DUOC PHAN TU" << endl;
    return -1;
  }
  int data = linkedlist->GetHead()->GetData();
  linkedlist->DeleteFirst();
  nNum--;
  return data;
}

Stack2::Stack2() : Stack() {}

void Stack2::PushStack(int data) {
  Element *newElement = new Element(data);
  linkedlist->InsertTail(newElement);
  nNum++;
}

int Stack2::PopStack() {
  if (isEmpty()) {
    cout << "STACK RONG, KHONG LAY DUOC PHAN TU" << endl;
    return -1;
  }
  int data = linkedlist->GetTail()->GetData();
  linkedlist->DeleteTail();
  nNum--;
  return data;
}

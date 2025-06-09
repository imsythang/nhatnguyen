#include "Stack2.h"

Stack2::Stack2() {
  this->linkedlist = new LinkedList();
  this->nNum = 0;
}
Stack2::~Stack2() {}
void Stack2::PushStack(int data) {
  // Thêm vào cuối
  Element *newElement = new Element(data);
  this->linkedlist->InsertTail(newElement);
  this->nNum++;
}
int Stack2::PopStack() {
  if (this->isEmpty()) {
    cout << "STACK RONG, KHONG LAY DUOC PHAN TU" << endl;
    return -1;
  }
  int data = linkedlist->GetTail()->GetData();
  linkedlist->DeleteTail();
  return data;
}
void Stack2::printStack() { this->linkedlist->Travel(); }
bool Stack2::isEmpty() { return (this->linkedlist->GetHead() == nullptr); }

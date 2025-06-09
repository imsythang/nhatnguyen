#include "Queue2.h"

Queue2::Queue2() {
  this->nNum = 0;
  this->linkedlist = new LinkedList();
}
Queue2::~Queue2() {}
void Queue2::EnQueue(int data) {

  Element *newElement = new Element(data);
  this->linkedlist->InsertTail(newElement);
}
int Queue2::DeQueue() {
  if (this->isEmpty()) {
    cout << "“QUEUE RONG, KHONG LAY DUOC PHAN TU" << endl;
    return -1;
  }
  int data = linkedlist->GetHead()->GetData();
  linkedlist->DeleteFirst();
  return data;
}
void Queue2::printQueue() { linkedlist->Travel(); }
bool Queue2::isEmpty() { return (this->linkedlist->GetHead() == nullptr); }

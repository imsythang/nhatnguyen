#include "Queue.h"

Queue::Queue() {
  linkedlist = new LinkedList();
  nNum = 0;
}

Queue::~Queue() { delete linkedlist; }

void Queue::printQueue() { linkedlist->Travel(); }

bool Queue::isEmpty() const { return (linkedlist->GetHead() == nullptr); }

Queue1::Queue1() : Queue() {}

void Queue1::EnQueue(int data) {
  Element *newElement = new Element(data);
  linkedlist->InsertFirst(newElement);
  nNum++;
}

int Queue1::DeQueue() {
  if (isEmpty()) {
    cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU" << endl;
    return -1;
  }
  int data = linkedlist->GetTail()->GetData();
  linkedlist->DeleteTail();
  nNum--;
  return data;
}

Queue2::Queue2() : Queue() {}

void Queue2::EnQueue(int data) {
  Element *newElement = new Element(data);
  linkedlist->InsertTail(newElement);
  nNum++;
}

int Queue2::DeQueue() {
  if (isEmpty()) {
    cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU" << endl;
    return -1;
  }
  int data = linkedlist->GetHead()->GetData();
  linkedlist->DeleteFirst();
  nNum--;
  return data;
}

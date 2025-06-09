#include "Queue1.h"

Queue1::Queue1()
{
  this->nNum = 0;
  this->linkedlist = new LinkedList();
}
Queue1::~Queue1(){}
void Queue1::EnQueue(int data)
{
  // Thêm phần tử mới vào cuối danh sách
  Element* newElement = new Element(data);
  this->linkedlist->InsertFirst(newElement);
}
int Queue1::DeQueue()
{
  if(this->isEmpty())
  {
    cout << "“QUEUE RONG, KHONG LAY DUOC PHAN TU" << endl;
    return -1;
  }
  int data = linkedlist->GetTail()->GetData();
  linkedlist->DeleteTail();
  return data;
}
void Queue1::printQueue()
{
  linkedlist->Travel();
}
bool Queue1::isEmpty() { return (this->linkedlist->GetHead() == nullptr); }

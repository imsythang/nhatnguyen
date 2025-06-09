#include "Stack1.h"

Stack1::Stack1() {
  this->linkedlist = new LinkedList();
  this->nNum = 0;
}
Stack1::~Stack1() {}
void Stack1::PushStack(int data)
{
  Element *newElement = new Element(data);
  this->linkedlist->InsertFirst(newElement);
  this->nNum++;
}
int Stack1::PopStack()
{
 if(this->isEmpty())
 {
   cout << "STACK RONG, KHONG LAY DUOC PHAN TU" << endl;
   return -1;
 }
 int data = linkedlist->GetHead()->GetData();
 linkedlist->DeleteFirst();
 return data;
}
void Stack1::printStack()
{
  this->linkedlist->Travel();
}
bool Stack1::isEmpty()
{
  return (this->linkedlist->GetHead() == nullptr);
}

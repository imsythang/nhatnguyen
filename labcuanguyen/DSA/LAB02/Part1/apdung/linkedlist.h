/// File: LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Element.h"

class LinkedList {
private:
  Element *head;
  Element *tail;
  int nNum;

public:
  LinkedList();
  virtual ~LinkedList();
  Element *GetHead() { return head; }
  void Sethead(Element *val) { head = val; }
  Element *GetTail() { return tail; }
  void SetTail(Element *val) { tail = val; }
  void InsertFirst(Element *);
  void InsertTail(Element *);
  bool DeleteFirst();
  void Travel();
  void RemoveAll();
  int SumList();
  int MaxList();
  int CountPrime();
  bool InsertAfterP(Element*, Element*);
  bool DeleteTail();
  bool DeleteElement(Element*);
  int CountValueX(int);
  bool Exist(int);
  void InsertTailNotDuplicate(Element*);
  void SplitList(int, LinkedList&, LinkedList&);
};

#endif // LINKEDLIST_H

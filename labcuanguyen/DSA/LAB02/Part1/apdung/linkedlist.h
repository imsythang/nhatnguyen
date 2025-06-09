/// File: LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "element.h"
#include <iostream>
using namespace std;

class LinkedList {
private:
  Element *head;
  Element *tail;
  int nNum;

public:
  LinkedList();
  virtual ~LinkedList();
  Element *GetHead() const { return head; }
  void Sethead(Element *val) { head = val; }
  Element *GetTail() const { return tail; }
  void SetTail(Element *val) { tail = val; }
  void InsertFirst(Element *p);
  void InsertTail(Element *p);
  void DeleteFirst();
  void DeleteTail();
  void Travel();
  void RemoveAll();
  int SumList();
  int MaxList();
  int CountPrime();
  bool InsertAfterP(Element *, Element *);
  bool DeleteElement(Element *);
  int CountValueX(int);
  bool Exist(int);
  void InsertTailNotDuplicate(Element *);
  void SplitList(int, LinkedList &, LinkedList &);
};

#endif // LINKEDLIST_H

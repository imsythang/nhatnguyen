/// File: linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "element.h"

class linkedlist {
private:
  element *head;
  element *tail;
  int nNum;

public:
  linkedlist();
  virtual ~linkedlist();
  element *Gethead() { return head; }
  void Sethead(element *val) { head = val; }
  element *Gettail() { return tail; }
  void Settail(element *val) { tail = val; }
  void InsertFirst(element *);
  void InsertTail(element *);
  bool DeleteFirst();
  void Travel();
  void RemoveAll();
  int SumList();
  int MaxList();
  int CountPrime();
  bool InsertAfterP(element*, element*);
  bool DeleteTail();
  bool DeleteElement(element*);
  int CountValueX(int);
  bool Exist(int);
  void InsertTailNotDuplicate(element*);
  void SplitList(int, linkedlist&, linkedlist&);

};

#endif // LINKEDLIST_H

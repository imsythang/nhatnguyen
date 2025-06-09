/// File: main.cpp

#include "LinkedList.h"
#include "Queue1.h"
#include "Stack1.h"
#include "Queue2.h"
#include "Stack2.h"
#include <iostream>

using namespace std;

int main() {
  LinkedList *list_ = new LinkedList();
  Element *e;
  e = new Element(9);
  list_->InsertTail(e);
  e = new Element(10);
  list_->InsertTail(e);
  e = new Element(8);
  list_->InsertTail(e);
  list_->Travel();
  // print
  list_->DeleteFirst();
  cout << "\n";
  list_->Travel();
  cout << "\n";
  LinkedList *list2 = new LinkedList();
  Element *e1 = new Element(1);
  list2->InsertTailNotDuplicate(e1);
  Element *e2 = new Element(2);
  list2->InsertTailNotDuplicate(e2);
  Element *e3 = new Element(1);
  list2->InsertTailNotDuplicate(e3);
  list2->Travel();

  // ---- TEST STACK AND QUEUE ----
  //  ---- STACK1 ----
  Stack1 *s1 = new Stack1();
  int x;
  cout << "Nhập lần lượt 3 giá trị vào Stack1 (Thêm đầu xóa đầu): ";
  for (int i = 0; i < 3; i++) {
    cin >> x;
    s1->PushStack(x);
  }
  for (int i = 0; i < 4; i++) {
    cout << "Pop: " << s1->PopStack() << endl;
  }
  // ---- STACK2 ----
  Stack2 *s2 = new Stack2();
  cout << "\nNhập lần lượt 3 giá trị vào Stack2 (Thêm cuối xóa cuối): ";
  for (int i = 0; i < 3; i++) {
    cin >> x;
    s2->PushStack(x);
  }
  for (int i = 0; i < 4; i++) {
    cout << "Pop: " << s2->PopStack() << endl;
  }
  // ---- QUEUE1 ----
  Queue1 *q1 = new Queue1();
  cout << "\nNhập lần lượt 3 giá trị vào Queue1 (Thêm cuối xóa đầu): ";
  for (int i = 0; i < 3; i++) {
    cin >> x;
    q1->EnQueue(x);
  }
  for (int i = 0; i < 4; i++) {
    cout << "Pop: " << q1->DeQueue() << endl;
  }
  // ---- QUEUE2 ----
  Queue2 *q2 = new Queue2();
  cout << "\nNhập lần lượt 3 giá trị vào Queue2 (Thêm đầu xóa cuối): ";
  for (int i = 0; i < 3; i++) {
    cin >> x;
    q2->EnQueue(x);
  }
  for (int i = 0; i < 4; i++) {
    cout << "Pop: " << q2->DeQueue() << endl;
  }
}

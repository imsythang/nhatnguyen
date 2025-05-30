#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node *next;

  Node(int val) : value(val), next(nullptr) {}
};
class CircularLinkedList {
private:
  Node *tail;

public:
  // constructor: trùng tên với class
  CircularLinkedList() : tail(nullptr) {}
  // Insert vào cuối danh sách
  void insertTail(Node *node) {
    // 1
    // 1->2->3->5->1
    // Thêm 4 vào cuối: 1->2->3->5->4->1
    if (!tail) {
      tail = node;
      tail->next = tail;
    } else {
      node->next = tail->next;
      tail->next = node;
      tail = node;
    }
  }
  void print() {
    if (!tail)
      return;
    Node *current = tail->next; // Bắt đầu từ node đầu tiên
    do {
      cout << current->value << " ";
      current = current->next; // Di chuyển đến node tiếp theo
    } while (current != tail->next); // Dừng khi quay lại node đầu tiên
    cout << endl;
  }
};
int main() {}

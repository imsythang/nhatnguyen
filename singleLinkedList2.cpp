#include <iostream>
using namespace std;

class Node {
public:
  // getter/setter
  int getValue() { return value; }
  void setValue(int val) { value = val; }
  int value;
  Node *next;
  Node(int val){
    value = val;
    next = nullptr;
  }
};
class SingleLinkedList {
private:
  Node *head;
  int count;

public:
  // Constructor: Trùng tên với class
  SingleLinkedList() {
    head = nullptr;
    count = 1;
  }
  // Destructor: Xoá giá trị
  ~SingleLinkedList() {}
  void insertNode(Node *node, int index) {
    if (index >= count || index < 0) {
      cout << "Vị trí thêm không hợp lệ!" << endl;
      return;
    }
    if (index == 0) {
      node->next = head;
      head = node;
      count++;
      return;
    }
    Node *current = head;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    node->next = current->next;
    current->next = node;
count++;
  }
  void print(){
    if(!head)
    {
        return;
    }
    Node* current = head;
    for(int i = 0; i < count - 1; i++){
        cout << current->value << " ";
        current = current->next;

    }
}
};
int main()
{
    SingleLinkedList* list =  new SingleLinkedList();
    // list->head = nullptr, count = 0;
    Node* n1 = new Node(2);
    // n1->value = 2
    list->insertNode(n1, 0);  // . ->
    Node* n2 = new Node(3);

    list->insertNode(n2, 1);

    Node* n3 = new Node(4);
    list->insertNode(n3, 0);
    list->print();

}

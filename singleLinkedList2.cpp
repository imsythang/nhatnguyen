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

public:
  // Constructor: Trùng tên với class
  SingleLinkedList() {
    head = nullptr;
  }
  // Destructor: Xoá giá trị
  ~SingleLinkedList() {}
  void insertNode(Node *node, int index) {
    if (index >= countNode() || index < 0) {
      cout << "Vị trí thêm không hợp lệ!" << endl;
      return;
    }
    if (index == 0) {
      node->next = head;
      head = node;
      return;
    }
    Node *current = head;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    node->next = current->next;
    current->next = node;
  }
  bool deleteNode(int val){
    if (head == nullptr){
      return false;
    }
    // delete head
    if(head->value == val){
      Node* temp = head;
      head = head->next;
      delete temp;
      return true;
    }
    Node* temp = head;
    while(temp->next != nullptr && temp->next->value != val){
      temp = temp->next;
    }
    if(temp->next == nullptr){
      return false;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    return true;
    //temp = v1
    // v1 v2 v3 v4
  }
  bool search(int val){
    Node* current = head;
    while(current != nullptr){
      if(current->value == val){
        return true;
      }
      current = current->next;

    }
    return false;
  }
  int countNode(){
    int count = 0;
    Node* current = head;
    while(current != nullptr){
      count++;
      current = current->next;
    }
    return count;
  }
  void deleteAll(){
    Node* current = head;
    while(current != nullptr){
      Node* temp = current;
      current = current->next;
      delete temp;
    }
    head = nullptr;
  }
  int sum(){
    int sum = 0;
    Node* current = head;
    while(current != nullptr){
      sum += current->value;
      current = current->next;

    }
    return sum;
  }

  void print(){
    if(!head)
    {
        return;
    }
    Node* current = head;
    for(int i = 0; i < countNode() - 1; i++){
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
    list->deleteNode(4);
    cout << "Sau khi xóa số 4: " << endl;
    list->print();
    cout << "Tổng: " << list->sum() << endl;
    cout << "Số lượng node: " << list->countNode() << endl;
    list->deleteAll();
    list->print();



}

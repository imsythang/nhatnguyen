#include "LinkedList.h"
LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}
LinkedList::~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *nextNode = current->GetNextPointer();
        delete current;
        current = nextNode;
    }
}
void LinkedList::insertFirst(int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->SetNextPointer(head);
        head = newNode;
    }
}
void LinkedList::insertLast(int data) {
    Node *newNode = new Node(data);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->SetNextPointer(newNode);
        tail = newNode;
    }
}
void LinkedList::deleteFirst() {
    if (head == nullptr) return; // Danh sách rỗng
    Node *temp = head;
    head = head->GetNextPointer();
    delete temp;
    if (head == nullptr) tail = nullptr; // Nếu danh sách trở nên rỗng
}
void LinkedList::deleteLast() {
    if (head == nullptr) return; // Danh sách rỗng
    if (head->GetNextPointer() == nullptr) { // Chỉ có một phần tử
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    Node *current = head;
    while (current->GetNextPointer()->GetNextPointer() != nullptr) {
        current = current->GetNextPointer();
    }
    delete current->GetNextPointer();
    current->SetNextPointer(nullptr);
    tail = current; // Cập nhật tail
}
bool LinkedList::count() const {
    int count = 0;
    Node *current = head;
    while (current != nullptr) {
        count++;
        current = current->GetNextPointer();
    }
    return count;
}
void LinkedList::printList() const {
    Node *current = head;
    while (current != nullptr) {
        cout << current->GetData() << " ";
        current = current->GetNextPointer();
    }
    cout << endl;
}


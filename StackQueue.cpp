#include <iostream>
using namespace std;

// ======= Phần tử danh sách liên kết đơn =======
class Node {
private:
    int data;
    Node* next;
public:
    Node(int val) : data(val), next(nullptr) {}
    int getData() { return data; }
    Node* getNext() { return next; }
    void setNext(Node* p) { next = p; }
};

// ======= Danh sách liên kết đơn =======
class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList() {
        // Giải phóng toàn bộ danh sách
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->getNext();
            delete temp;
        }
    }

    Node* getHead() { return head; }
    Node* getTail() { return tail; }

    // Thêm node vào đầu danh sách
    void insertFirst(Node* node) {
        if (head == nullptr) {
            head = tail = node;
        } else {
            node->setNext(head);
            head = node;
        }
    }

    // Thêm node vào cuối danh sách
    void insertTail(Node* node) {
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->setNext(node);
            tail = node;
        }
    }

    // Xóa node đầu danh sách
    bool deleteFirst() {
        if (head == nullptr) return false;
        Node* temp = head;
        head = head->getNext();
        if (head == nullptr) tail = nullptr; // danh sách rỗng sau xóa
        delete temp;
        return true;
    }

    // Kiểm tra danh sách rỗng
    bool isEmpty() {
        return head == nullptr;
    }

    // In danh sách ra màn hình
    void printList() {
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->getData() << " ";
            cur = cur->getNext();
        }
        cout << endl;
    }
};

// ======= Stack cài đặt dựa trên danh sách liên kết đơn =======
class Stack {
private:
    LinkedList list;
public:
    void push(int val) {
        Node* node = new Node(val);
        list.insertFirst(node);  // thêm vào đầu danh sách
    }

    int pop() {
        if (list.isEmpty()) {
            cout << "STACK RONG, KHONG LAY DUOC PHAN TU\n";
            return -1; // hoặc throw exception
        }
        int val = list.getHead()->getData();
        list.deleteFirst();
        return val;
    }

    void printStack() {
        cout << "Stack: ";
        list.printList();
    }
};

// ======= Queue cài đặt dựa trên danh sách liên kết đơn =======
class Queue {
private:
    LinkedList list;
public:
    void enqueue(int val) {
        Node* node = new Node(val);
        list.insertTail(node);  // thêm vào cuối danh sách
    }

    int dequeue() {
        if (list.isEmpty()) {
            cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU\n";
            return -1;
        }
        int val = list.getHead()->getData();
        list.deleteFirst();
        return val;
    }

    void printQueue() {
        cout << "Queue: ";
        list.printList();
    }
};

// ======= Hàm main thử nghiệm =======
int main() {
    Stack s;
    Queue q;

    cout << "=== STACK ===\n";
    s.push(10);
    s.push(20);
    s.push(30);
    s.printStack();

    cout << "Pop: " << s.pop() << endl;
    s.printStack();

    cout << "Pop: " << s.pop() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Pop: " << s.pop() << endl; // thử pop khi rỗng

    cout << "\n=== QUEUE ===\n";
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.printQueue();

    cout << "Dequeue: " << q.dequeue() << endl;
    q.printQueue();

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl; // thử dequeue khi rỗng

    return 0;
}

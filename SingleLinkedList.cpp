#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
  Node *head;
  bool isPrime(int n) {
    if (n < 2)
      return false;
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0)
        return false;
    return true;
  }
  Node *getTail(Node *cur) {
    while (cur && cur->next)
      cur = cur->next;
    return cur;
  }

public:
  SinglyLinkedList() : head(nullptr) {}

  ~SinglyLinkedList() {
    Node *current = head;
    while (current != nullptr) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
  }

  bool isEmpty() { return head == nullptr; }
  // Begin: Insert
  //  Thêm phần tử vào đầu danh sách
  void insertAtHead(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
  }

  // Thêm phần tử vào cuối danh sách
  void insertAtTail(int val) {
    Node *newNode = new Node(val);
    if (head == nullptr) {
      head = newNode;
      return;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  // Thêm phần tử sau node có giá trị key
  bool insertAfter(int key, int val) {
    Node *temp = head;
    while (temp != nullptr && temp->data != key) {
      temp = temp->next;
    }
    if (temp == nullptr)
      return false; // không tìm thấy key
    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    return true;
  }
  // End: Insert
  // Begin: Delete
  // Xóa phần tử đầu danh sách
  bool deleteHead() {
    if (head == nullptr)
      return false;
    Node *temp = head;
    head = head->next;
    delete temp;
    return true;
  }

  // Xóa phần tử cuối danh sách
  bool deleteTail() {
    if (head == nullptr)
      return false;
    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      return true;
    }
    Node *temp = head;
    while (temp->next->next != nullptr) {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return true;
  }

  // Xóa phần tử có giá trị val
  bool deleteValue(int val) {
    if (head == nullptr)
      return false;
    if (head->data == val) {
      return deleteHead();
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != val) {
      temp = temp->next;
    }
    if (temp->next == nullptr)
      return false; // không tìm thấy val
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    return true;
  }
  // End: Delete
  // Begin: Search
  // Tìm kiếm phần tử có giá trị val
  bool search(int val) {
    Node *temp = head;
    while (temp != nullptr) {
      if (temp->data == val)
        return true;
      temp = temp->next;
    }
    return false;
  }
  // End: Search
  // In danh sách
  void printList() {
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL\n";
  }
  // Hàm đếm số phần tử trong danh sách
  int countNodes() {
    int count = 0;
    Node *temp = head;
    while (temp != nullptr) {
      count++;
      temp = temp->next;
    }
    return count;
  }
  // Hàm đảo ngược danh sách liên kết đơn
  void reverseList() {
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;
    while (current != nullptr) {
      next = current->next; // lưu lại phần tử kế tiếp
      current->next = prev; // đảo hướng con trỏ
      prev = current;
      current = next;
    }
    head = prev; // cập nhật head mới
  }
  // Xóa tất cả phần tử trong danh sách
  void removeAll() {
    Node *current = head;
    while (current != nullptr) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
    head = nullptr;
  }

  // Tính tổng các phần tử trong danh sách
  int SumList() {
    int sum = 0;
    Node *temp = head;
    while (temp != nullptr) {
      sum += temp->data;
      temp = temp->next;
    }
    return sum;
  }

  // Tìm giá trị lớn nhất trong danh sách
  int MaxList() {
    if (head == nullptr) {
      cout << "Danh sách rỗng!\n";
      return -1; // Hoặc giá trị phù hợp báo lỗi
    }
    int maxVal = head->data;
    Node *temp = head->next;
    while (temp != nullptr) {
      if (temp->data > maxVal)
        maxVal = temp->data;
      temp = temp->next;
    }
    return maxVal;
  }

  // Đếm số phần tử là số nguyên tố trong danh sách
  int CountPrime() {
    int count = 0;
    Node *temp = head;
    while (temp != nullptr) {
      if (isPrime(temp->data))
        count++;
      temp = temp->next;
    }
    return count;
  }

  // Cập nhật tất cả phần tử có giá trị oldVal thành newVal
  void updateValueAll(int oldVal, int newVal) {
    Node *temp = head;
    while (temp != nullptr) {
      if (temp->data == oldVal)
        temp->data = newVal;
      temp = temp->next;
    }
  }

  // Cập nhật phần tử đầu tiên có giá trị oldVal thành newVal
  bool updateValue(int oldVal, int newVal) {
    Node *temp = head;
    while (temp != nullptr) {
      if (temp->data == oldVal) {
        temp->data = newVal;
        return true;
      }
      temp = temp->next;
    }
    return false; // không tìm thấy
  }
  // Sort
  //  ========== 1. Selection Sort ===========
  void selectionSort() {
    for (Node *i = head; i != nullptr; i = i->next) {
      Node *minNode = i;
      for (Node *j = i->next; j != nullptr; j = j->next) {
        if (j->data < minNode->data)
          minNode = j;
      }
      if (minNode != i)
        swap(i->data, minNode->data);
    }
  }
  // ========== 2. Bubble Sort ===========
  void bubbleSort() {
    if (!head)
      return;
    bool swapped;
    Node *end = nullptr;
    do {
      swapped = false;
      Node *current = head;
      while (current->next != end) {
        if (current->data > current->next->data) {
          swap(current->data, current->next->data);
          swapped = true;
        }
        current = current->next;
      }
      end = current;
    } while (swapped);
  }
  // Merge Sort helper: tách list thành 2 nửa
  Node *getMiddle(Node *start) {
    if (!start)
      return nullptr;
    Node *slow = start;
    Node *fast = start->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  // Merge 2 list đã sắp xếp
  Node *sortedMerge(Node *a, Node *b) {
    if (!a)
      return b;
    if (!b)
      return a;
    if (a->data <= b->data) {
      a->next = sortedMerge(a->next, b);
      return a;
    } else {
      b->next = sortedMerge(a, b->next);
      return b;
    }
  }

  // Đệ quy Merge Sort
  Node *mergeSort(Node *start) {
    if (!start || !start->next)
      return start;
    Node *mid = getMiddle(start);
    Node *nextOfMid = mid->next;
    mid->next = nullptr;
    Node *left = mergeSort(start);
    Node *right = mergeSort(nextOfMid);
    return sortedMerge(left, right);
  }

  // QuickSort helper: partition danh sách quanh pivot
  Node *partition(Node *start, Node *end, Node **newHead, Node **newEnd) {
    Node *pivot = end;
    Node *prev = nullptr, *cur = start, *tail = pivot;

    while (cur != pivot) {
      if (cur->data < pivot->data) {
        if ((*newHead) == nullptr)
          (*newHead) = cur;
        prev = cur;
        cur = cur->next;
      } else {
        if (prev)
          prev->next = cur->next;
        Node *tmp = cur->next;
        cur->next = nullptr;
        tail->next = cur;
        tail = cur;
        cur = tmp;
      }
    }

    if ((*newHead) == nullptr)
      (*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
  }

  Node *quickSort(Node *start, Node *end) {
    if (!start || start == end)
      return start;
    Node *newHead = nullptr, *newEnd = nullptr;

    Node *pivot = partition(start, end, &newHead, &newEnd);

    if (newHead != pivot) {
      Node *tmp = newHead;
      while (tmp->next != pivot)
        tmp = tmp->next;
      tmp->next = nullptr;

      newHead = quickSort(newHead, tmp);

      tmp = getTail(newHead);
      tmp->next = pivot;
    }

    pivot->next = quickSort(pivot->next, newEnd);
    return newHead;
  }
};

int main() {
  SinglyLinkedList list;

  // Thêm phần tử
  list.insertAtHead(10);
  list.insertAtHead(5);
  list.insertAtTail(20);
  list.insertAtTail(30);
  list.printList(); // 5 -> 10 -> 20 -> 30 -> NULL

  // Thêm sau giá trị 10
  if (list.insertAfter(10, 15))
    cout << "Inserted 15 after 10\n";
  else
    cout << "Value 10 not found\n";
  list.printList(); // 5 -> 10 -> 15 -> 20 -> 30 -> NULL

  // Tìm kiếm
  cout << "Search 20: " << (list.search(20) ? "Found\n" : "Not Found\n");
  cout << "Search 100: " << (list.search(100) ? "Found\n" : "Not Found\n");

  // Xóa phần tử đầu
  list.deleteHead();
  list.printList(); // 10 -> 15 -> 20 -> 30 -> NULL

  // Xóa phần tử cuối
  list.deleteTail();
  list.printList(); // 10 -> 15 -> 20 -> NULL

  // Xóa phần tử có giá trị
  if (list.deleteValue(15))
    cout << "Deleted 15\n";
  else
    cout << "Value 15 not found\n";
  list.printList(); // 10 -> 20 -> NULL

  return 0;
}

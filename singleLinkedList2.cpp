#include <iostream>
using namespace std;

class Node {
public:
  // getter/setter
  int getValue() { return value; }
  void setValue(int val) { value = val; }
  int value;
  Node *next;
  Node(int val) {
    value = val;
    next = nullptr;
  }
};
class SingleLinkedList {
private:
  Node *head;

public:
  // Constructor: Trùng tên với class
  SingleLinkedList() { head = nullptr; }
  // Destructor: Xoá giá trị
  ~SingleLinkedList() {}
  void insertNode(Node *node, int index) {
    if (index > countNode() || index < 0) {
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
  bool deleteNode(int val) {
    if (head == nullptr) {
      return false;
    }
    // delete head
    if (head->value == val) {
      Node *temp = head;
      head = head->next;
      delete temp;
      return true;
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->value != val) {
      temp = temp->next;
    }
    if (temp->next == nullptr) {
      return false;
    }
    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    return true;
    // temp = v1
    //  v1 v2 v3 v4
  }
  bool search(int val) {
    Node *current = head;
    while (current != nullptr) {
      if (current->value == val) {
        return true;
      }
      current = current->next;
    }
    return false;
  }
  int countNode() {
    int count = 0;
    Node *current = head;
    while (current != nullptr) {
      count++;
      current = current->next;
    }
    return count;
  }
  void deleteAll() {
    Node *current = head;
    while (current != nullptr) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
    head = nullptr;
  }
  int sum() {
    int sum = 0;
    Node *current = head;
    while (current != nullptr) {
      sum += current->value;
      current = current->next;
    }
    return sum;
  }
  int maxValue() {
    // exception: danh sách rỗng
    if (head == nullptr) {
      cout << "Danh sách rỗng!" << endl;
      return -1; // Hoặc giá trị phù hợp báo lỗi
    }
    int maxVal = head->value;
    Node *current = head->next;
    // 1 2 3 4 5 if (current > maxVal)
    while (current != nullptr) {
      if (current->value > maxVal) {
        maxVal = current->value;
      }
      current = current->next;
    }
    return maxVal;
  }
  // Sort danh sách
  // Selection Sort: Sắp xếp bằng cách tìm phần tử nhỏ nhất và đưa lên đầu
  // Swap: Swap 2 ngôi nhà, swap giá trị của 2 ngôi nhà
  void selectionSort() {
    if (countNode() < 2) {
      return; // Không cần sắp xếp nếu danh sách rỗng hoặc chỉ có 1 phần tử
    }
    Node *current1 = head;
    // 3 1 2 5 4 6
    // 1 3 2 5 4 6
    // 1 2 3 5 4 6
    // 1 2 3 5 4 6
    // 1 2 3 4 5 6
    while (current1 != nullptr) {
      Node *minNode = current1;
      Node *current2 = current1->next;
      while (current2 != nullptr) {
        if (current2->value < minNode->value) {
          minNode = current2; // Tìm phần tử nhỏ nhất
        }
        current2 = current2->next;
      }
      swap(minNode->value, current1->value);
    }
  }
  // Merge Sort: Chia danh sách thành 2 nửa, sắp xếp từng nửa và hợp nhất
  // Left + Right
  // Điểm chia: Middle = left + (right - left)/2
  // 2 8 1 13 5 9 4
  // Left1 = 2 8 1 13 |  Right1 = 5 9 4
  // Left2 = 2 8 | Right2 = 1 13 |
  // Left3 = 2 | Right3 = 8
  // 2 -> 8 + 1 -> 13 = 1 -> 2 -> 8 -> 13
  Node *sortedMerge(Node *left, Node *right) // Hợp
  {
    if (!left)
      return right;
    if (!right)
      return left;
    // Đệ quy
    if (left->value < right->value) {
      left->next = sortedMerge(left->next, right);
      return left;
    } else {
      right->next = sortedMerge(left, right->next);
      return right;
    }
  }
  // s1 f2 s3 4 5
  // Slow: Mỗi vòng lặp nó sẽ bước 1 bước |
  // Fast: Mỗi vòng lặp nó sẽ bước 2 bước ||
  // s1 f2 3 4 5 6
  Node *getMiddle(Node *head) {
    if (!head)
      return nullptr;
    Node *slow = head;
    Node *fast = head->next; // Bước đầu tiên, fast sẽ bước 2 bước
    while (fast && fast->next) {
      slow = slow->next;       // Bước 1 bước
      fast = fast->next->next; // Bước 2 bước
    }
    return slow;
  }
  Node *mergeSort(Node *start) // Chia
  {
    if (countNode() < 2)
      return start;
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    // 1 -> 2 -> 3 -> 4 | 5 -> 6 -> 7
    // Đệ quy: Điều kiện dừng, điều kiện đệ quy
    Node *mid = getMiddle(start);
    Node *startOfRight = mid->next;
    mid->next = nullptr;
    Node *left = mergeSort(start);
    Node *right = mergeSort(startOfRight);
    return sortedMerge(left, right);
  }
  // Cập nhật giá trị từ oldValue sang newValue
  // 3 4 1 5 8 9 5 2
  // OldValue = 5, NewValue = 10
  // 3 4 1 10 8 9 10 2
  // current | if(current->value == oldValue)
  // thay đổi oldValue hay thay đổi current->value
  void updateValue(int oldValue, int newValue) {
    Node *current = head;
    while (current) {
      if (current->value == oldValue) {
        current->value = newValue;
      }
      current = current->next;
    }
  }
  // Đếm số phần tử là số nguyên tố trong danh sách
  // Số nguyên tố là số chỉ chia hết cho 1 và chính nó
  // 19 (1 19) - 2 18
  bool isPrime(int n) {
    if (n < 2)
      return false;
    for (int i = 2; i <= n - 1; i++) {
      if (n % i == 0)
        return false; // Chia hết cho i
    }
    return true;
  }
  int countPrime() {
    // 1 2 3 4 5 6 7 8 9 10
    int count = 0;
    Node *current = head;
    while (current != nullptr) {
      if (isPrime(current->value)) {
        count++;
      }
      current = current->next;
    }
    return count;
  }
  void print() {
    if (!head) {
      return;
    }
    Node *current = head;
    for (int i = 0; i < countNode(); i++) {
      cout << current->value << " ";
      current = current->next;
    }
    cout << endl;
  }
};
int main() {
  SingleLinkedList *list = new SingleLinkedList();
  // list->head = nullptr, count = 0;
  Node *n1 = new Node(2);
  // n1->value = 2
  list->insertNode(n1, 0); // . ->
  Node *n2 = new Node(3);

  list->insertNode(n2, 1);

  Node *n3 = new Node(4);
  list->insertNode(n3, 0);
  list->print();
  list->deleteNode(4);
  cout << "Sau khi xóa số 4: ";
  list->print();
  list->insertNode(new Node(5), 2);
  cout << "Sau khi thêm số 5 vào vị trí 2: ";
  list->print();
  list->insertNode(new Node(6), 3);
  list->insertNode(new Node(7), 1);
  cout << "Danh sách sau khi thêm các phần tử: ";
  list->print();
  cout << "Tổng: " << list->sum() << endl;
  cout << "Số lượng node: " << list->countNode() << endl;
  cout << "Giá trị lớn nhất: " << list->maxValue() << endl;
  cout << "Số lượng số nguyên tố: " << list->countPrime() << endl;
  list->selectionSort();
  cout << "Danh sách sau khi sắp xếp: ";
  list->print();
  list->updateValue(5, 10);
  cout << "Danh sách sau khi cập nhật giá trị 5 thành 10: ";
  list->print();
  list->deleteAll();
  cout << "Sau khi xóa tất cả: ";
  list->print();
}

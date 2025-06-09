#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;
class Node {
private:
  int data; // Dữ liệu của node
  Node *next;  // Con trỏ đến node tiếp theo
public:
  // Constructor: khởi tạo node với dữ liệu và con trỏ tiếp theo
  Node(int &data, Node *next = nullptr){}
  // Destructor: giải phóng bộ nhớ nếu cần thiết
  ~Node();
  // Getter: lấy dữ liệu của node
  int GetData() ;
  Node* GetNextData() ;
  // Setter: đặt dữ liệu cho node
  void SetData(int data);
  // Setter: đặt con trỏ tiếp theo cho node
  void SetNextData(Node *next);
}
#endif // !NODE_H


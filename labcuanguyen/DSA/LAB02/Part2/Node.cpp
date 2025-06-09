#include "Node.h"
Node::Node(int data, Node *next = nullptr) : data(data), next(next) {}

// Getter cho dữ liệu
int Node::GetData() const { return data; }

// Getter cho con trỏ tiếp theo
Node* Node::GetNextPointer() const { return next; }

// Setter cho dữ liệu
void Node::SetData(int data) { this->data = data; }

// Setter cho con trỏ tiếp theo
void Node::SetNextPointer(Node *next) { this->next = next; }

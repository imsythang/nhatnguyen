#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
class Node {
private:
  Node *left;
  Node *right;
  int key;

public:
  Node();
  Node(int);
  virtual ~Node();
  // Get và Set
  Node *getLeft();
  void setLeft(Node*);
  Node *getRight();
  void setRight(Node *);
  int getKey();
  void setKey(int)
}

#endif // DEBUG

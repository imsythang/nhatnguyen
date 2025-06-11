#ifndef BST_H
#define BST_H
#include "Node.h"

class BST
{
private:
  Node* root;
public:
  BST();
  ~BST();
  bool insertNode(Node*);
  Node* getRoot();
  void setRoot(Node*);
  void deleteNode(Node*);
  void travelNLR();
  void travelLNR();
  void travelLRN();
  void NLR(Node *);
  void LNR(Node *);
  void LRN(Node *);
  Node* search(int);
}

#endif // !BST_H



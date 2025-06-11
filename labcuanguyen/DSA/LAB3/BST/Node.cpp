#include "Node.h"

Node::Node() {
  this->left = nullptr;
  this->right = nullptr;
  this->key = -1;
}
Node::Node(int key) {
  this->left = nullptr;
  this->right = nullptr;
  this->key = key;
}
Node::~Node() {
  delete this->left;
  delete this->right;
  this->key = -1;
}
// Get và Set
Node *Node::getLeft() { return this->left; }
void Node::setLeft(Node *node) { this->left = node; }
Node *Node::getRight() { return this->right; }
void Node::setRight(Node *node) { this->right = node; }
int Node::getKey() { return this->key; }
void Node::setKey(int key) { this->key = key; }

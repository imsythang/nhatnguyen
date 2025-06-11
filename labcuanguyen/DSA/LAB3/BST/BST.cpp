#include "BST.h"

BST::BST()
{
  this->root = nullptr;
}
BST::~BST()
{
  this->root = nullptr;
}
Node *BST::getRoot()
{
  return this->root;
}
void BST::setRoot(Node * node)
{
  this->root = node;
}
void BST::insertNode(Node* newNode)
{
  // Nếu cây rỗng -> node đó là root
  if(root == nullptr) {
    root = newNode;
    return true;
  }
  Node* parent = nullptr;
  Node* current = root;
  while(current != nullptr)
  {
   //  13 -> 10 15
    // 10 -> 9 12
    // Thêm 14 -> Con trái của 15
    parent = current;
    if(newNode->getKey() < current->getKey())
    {
      current = current->getLeft();
    }
    else if(newNode->getKey() > current->getKey())
    {
      current = current->getRight();
    }
    else return false; // Trùng key -> Không thêm
  }
  // Đã tìm được vị trí, xác định thêm vào trái hay phải của parent
  if(newNode->getKey() < parent->getKey())
  {
    parent->setLeft(newNode);
  }
  else parent->setRight(newNode);
  return true;
}
void BST::deleteNode(Node *)
{

}
// Travelsal
void BST::travelNLR()
{
  NLR(this->root);
  cout << endl;
}
void BST::travelLNR();
void BST::travelLRN();
void BST::NLR(Node * root); // NLR Là hàm phụ trợ của travelNL
{
  // Duyệt node trước -> In ra trước
  // Đi qua trái
  // Hết trái -> Đi qua phải
  if(node != nullptr)
  {
    cout << node->getKey() << " ";
    NLR(root->getLeft());
    NLR(root->getRight());
  }
}
void BST::LNR(Node * root);
void BST::LRN(Node * root);
Node*BST::search(int key)
{
  Node* current = root;
  while(current != nullptr)
  {
    if(current->getKey() == key)
    {
      return current;
    }
    else if(current->getKey() < key)
    {
      current = current->getRight();
    }
    else
    {
      current = current->getLeft();
    }
  }
  return nullptr; // Không tìm thấy
}

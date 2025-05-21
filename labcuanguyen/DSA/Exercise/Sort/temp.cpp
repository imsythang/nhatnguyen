#include <iostream>
using namespace std;
// Pointer và reference
// - Pointer: là biến lưu địa chỉ của biến khác(*)
void swap(int &a, int &b) {
  // int &a = a1;
  // int &b = a2;
  int temp = a;
  a = b;
  b = temp;
}
int main() {
  int a = 10;
  int *p = &a;
  cout << "a = " << *p << endl;
  cout << "p = " << p << endl;
  int a1 = 10, a2 = 20;
  swap(a1, a2); //
  cout << "a1 = " << a1 << endl;
  cout << "a2 = " << a2 << endl;
}

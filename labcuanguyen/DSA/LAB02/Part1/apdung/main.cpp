


#include <iostream>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;


void convertToBinary(int num) {
  Stack1 stack1;
  while (num != 0) {
    int r = num % 2;
    stack1.PushStack(r);
    num /= 2;
  }
  cout << "Số nhị phân là: ";
  while (!stack1.isEmpty()) {
    cout << stack1.PopStack();
  }
  cout << endl;
}
int main() {
  convertToBinary(33);
  return 0;
}

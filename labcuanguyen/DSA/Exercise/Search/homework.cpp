#include <iostream>
using namespace std;
// BÀI 1
int sumArr(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i <= n - 1; i++) {
    sum += arr[i];
  }
  return sum;
}
int productArr(int arr[], int n) {
  int product = 0 + 1;
  for (int i = 0; i <= n - 1; i++) {
    product *= arr[i];
  }
  return product;
}

// BÀI 2
void swap(int *a, int *b) {
  // a
  int temp = *a;
  *a = *b;
  *b = temp;
}
int main() {
  int n;
  cout << "Nhập số phần tử của mảng: ";
  cin >> n;

  if (n <= 0 || n > 100) {
    cout << "Số phần tử không hợp lệ" << endl;
    return 1;
  }

  int arr[100];
  cout << "Nhập các phần tử trong mảng:" << endl;
  for (int i = 0; i < n; i++) {
    cout << "a[" << i << "] = ";
    cin >> arr[i];
  }

  int sum = sumArr(arr, n);
  cout << "Tổng các phần tử trong mảng: " << sum << endl;

  int x, y;

  cout << "Nhập số thứ nhất: ";
  cin >> x;
  cout << "Nhập số thứ hai: ";
  cin >> y;

  cout << "Trước khi hoán đổi: a = " << x << ", b = " << y << endl;
  swap(&x, &y);
  cout << "Sau khi hoán đổi: a = " << x << ", b = " << y << endl;

  return 0;
}

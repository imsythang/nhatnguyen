
#include <iostream>
using namespace std;

// BÀI 1
int sumArr(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

// BÀI 2
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// BÀI 3
void reverseArr(int a[], int n) {
  for (int i = 0; i < n / 2; i++) {
    swap(a[i], a[n - 1 - i]);
  }

  cout << "Mảng sau khi đảo ngược: ";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
// BÀI 4
int findMax(int a[], int n) {
  int maxCount = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > maxCount) {
      maxCount = a[i];
    }
  }
  return maxCount;
}

// BÀI 5
void sortArrayAscending(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
      }
    }
  }

  cout << "Mảng sau khi sắp xếp tăng dần: ";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
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
  swap(x, y);
  cout << "Sau khi hoán đổi: a = " << x << ", b = " << y << endl;

  reverseArr(arr, n);

  int maxCount = findMax(arr, n);
  cout << "Phần tử lớn nhất trong mảng: " << maxCount << endl;

  sortArrayAscending(arr, n);

  return 0;
}

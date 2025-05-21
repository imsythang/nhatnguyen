/*
1. Bổ sung các hàm trên vào chương trình mẫu (CacThuatToanSapXep) đồng thời thay
đổi hàm main và file input để  sắp xếp dãy số nguyên sau tăng dần: 42  23  74 11
65  58  94  36  99  87
2. Sửa lại chương trình để đếm số phép gán và số phép so sánh sự dụng trong hàm
QuickSort.
*/
#include <iostream>
using namespace std;

int count1 = 0, count2 = 0;
void Swap(int &a, int &b) {
  // int& a = a[i], int& b = a[j]
  int temp = a;
  a = b;
  b = temp;
  count1 += 3;
}
void QuickSort(int a[], int left, int right) {
  int i, j, x;
  if (left >= right) {
    count2++;
    return;
  }
  x = a[(left + right) / 2]; // chọn phần tử giữa làm giá trị mốc
  i = left;
  j = right;
  count1 += 3;
  while (i < j) {
    count2++;
    while (a[i] < x) {
      i++;
      count1++; // i = i + 1
      count2++;
    }

    while (a[j] > x) {
      j--;
      count2++;
    }
    if (i <= j) {
      count2++;
      Swap(a[i], a[j]);
      i++;
      j--;
      count1 += 2;
    }
  }

  QuickSort(a, left, j);
  QuickSort(a, i, right);
}

int main() {
  int arr[] = {42, 23, 74, 11, 65, 58, 94, 36, 99, 87};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Mang truoc khi sap xep: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  QuickSort(arr, 0, n - 1);
  cout << "Mang sau khi sap xep: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << "Số phép gán là: " << count1 << end;
  cout << "Số phép so sánh là: " << count2 << endl;
}

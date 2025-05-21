/*Bài 2. Nhập dữ liệu và
sắp xếp mảng A[n] tăng dần. Sử dụng giải thuật tìm kiếm nhị phân để tìm phần tử
có giá trị bằng X ở trong mảng A sau đó xóa nó khỏi A nếu tìm thấy*/

// int a[] = {12, 15, 19, 22, 25, 28, 31, 35, 39, 42};  n = 10
// arr[i] = arr[i + 1]
// int a[] = {12, 15, 19, 22, 25, 31, 35, 39, 42} n--;
// left = 0, right = n - 1;
// while (left <= right) { int mid = (left + right) / 2; if(a[mid] == X) else
// if(a[mid] < X) else

#include <iostream>
using namespace std;
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    bool flag = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        flag = true;
      }
    }
    if (flag ==
        false) // Nếu không có sự hoán đổi nào xảy ra thì mảng đã được sắp xếp
      break;
  }
}
int binarySearch(int arr[], int n, int X) {
  int left = 0, right = n - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == X) {
      return mid; // Trả về chỉ số của phần tử tìm thấy
    } else if (arr[mid] < X) {
      left = mid + 1; // Tìm kiếm trong nửa bên phải
    } else {
      right = mid - 1; // Tìm kiếm trong nửa bên trái
    }
  }
  return -1; // Không tìm thấy phần tử
}
int main() {
  int A[100];
  int n;
  cout << "Nhập số phần tử của mảng A: ";
  cin >> n;
  cout << "Nhập mảng: " << endl;
  for (int i = 0; i < n; i++) {
    cout << "Nhập phần tử thứ " << i + 1 << ": ";
    cin >> A[i];
  }
  bubbleSort(A, n);
  int X;
  cout << "Nhập giá trị X cần tìm: ";
  cin >> X;
  int index = binarySearch(A, n, X);
  if (index == -1)
    cout << "Không tìm thấy phần tử " << X << " trong mảng." << endl;
  else {
    cout << "Tìm thấy phần tử " << X << " tại chỉ số " << index << "." << endl;
    for (int i = index; i <= n - 2; i++) {
      A[i] = A[i + 1]; // Dịch chuyển các phần tử về bên trái
    }
    n--;
    cout << "Mảng sau khi xóa phần tử: ";
    for (int i = 0; i < n; i++) {
      cout << A[i] << " ";
    }
    cout << endl;
  }
}

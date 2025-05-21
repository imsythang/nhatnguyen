/*Thuật toán sắp xếp các phần tử trên một mảng A
VD: 1 -> 4000 search: 3569
Left = 1, Right = 4000, mid = (left + right)/2 = 4001/2 = 2000,5 = 2000
mid < search => left = mid + 1 = 2001
2001 - 4000
4 thuật toán sắp xếp:
1. Selection sort (Sắp xếp chọn)
Nguyên lý: Chọn phần tử nhỏ nhất trong mảng và hoán đổi với phần tử đầu tiên
=> Chọn phần tử nhỏ thứ hai trong mảng còn lại và hoán đổi với phần tử thứ hai
=> Chọn phần tử nhỏ thứ ba trong mảng còn lại và hoán đổi với phần tử thứ ba
...
=> Chọn phần tử nhỏ thứ n trong mảng còn lại và hoán đổi với phần tử thứ n
Ví dụ: Mảng ban đầu: [12, 2, 8, 5, 1]
Bước 1: Tìm min trong mảng [12, 2, 8, 5, 1] => min = 1 => Swap 1 với 12 => [1,
2, 8, 5, 12] Bước 2: Tìm min trong mảng [2, 8, 5, 12] => min = 2 => Swap 2 với 2
=> [1, 2, 8, 5, 12] Bước 3: Tìm min trong mảng [8, 5, 12] => min = 5 => Swap 5
với 8 => [1, 2, 5, 8, 12] Bước 4: Tìm min trong mảng [8, 12] => min = 8 => Swap
8 với 8 => [1, 2, 5, 8, 12] => Stop for(int i = 0; i < n - 1; i++)

{
    int minIndex = i;
    for(int j = i + 1; j < n; j++)
    {
        if(arr[j] < arr[minIndex])
        {
            minIndex = j;
        }
    }
    swap(arr[i], arr[minIndex]);
}
2. Quick sort (Sắp xếp nhanh) - Giải thuật chia để trị
- Pivot (chốt) là phần tử phải thỏa mãn:
    Trái < pivot
    Giữa = pivot
    Phải > pivot
Pivot thường là phần tử ở giữa, đầu, cuối mảng
A = [12, 4, 5, 8, 3, 7]
pivot = 5
Left = [4, 3] => Sắp xếp: [3, 4]
Right = [12, 8, 7] => Sắp xếp: [7, 8, 12]
=> Kết quả: Left + pivot + Right = [3, 4] + [5] + [7, 8, 12] = [3, 4, 5, 7, 8,
12]
=> Đệ quy: Chia để trị
- Đệ quy là một phương pháp lập trình trong đó một hàm gọi lại chính nó để giải
quyết một bài toán. Đệ quy thường được sử dụng để giải quyết các bài toán có cấu
trúc lặp lại hoặc phân chia thành các phần nhỏ hơn.
- Đệ quy có hai phần chính: điều kiện dừng và điều kiện đệ quy. Điều kiện dừng
là điều kiện mà khi đạt được, hàm sẽ không gọi lại chính nó nữa. Điều kiện đệ
quy là điều kiện mà hàm sẽ gọi lại chính nó với các tham số khác nhau để giải
quyết bài toán nhỏ hơn.
- Đệ quy có thể được sử dụng để giải quyết nhiều bài toán khác nhau, bao gồm
tính toán giai thừa, tìm kiếm nhị phân, sắp xếp nhanh (QuickSort), và nhiều
thuật toán khác.
Deadline: 11:59 AM 14/05/2025
3. Merge sort (Sắp xếp hợp nhất)
- Giải thuật chia để trị
- Idea: Chia mảng thành 2 nửa, sắp xếp từng nửa và hợp nhất lại
- Mảng có 1 phần tử thì đã được sắp xếp
- Đầu tiên,
- VD: [38, 27, 43, 3, 9, 82, 10]
n/2 = 3,5 = 3 | int x = left + (right - left)/2
=> L = [38, 27, 43, 3] và R = [9, 82, 10]
- Sắp xếp [38, 27, 43] n = 3
- [38] và [27, 43]
- Sắp xếp [27, 43] n = 2
- [27] và [43] Divide: Chia - Conquer: Chinh phục (Merge: Hợp nhất)
- 27 < 43 => [27, 43]
- Hợp nhất với [38], so sánh lần lượt: 38 lớn hơn 27 => Đặt 27 vào trước
- 38 với 43 => 38 < 43 => Đặt 38 vào trước
[27, 38, 43]
- Right array: [3, 9, 82, 10] n = 4
- [3, 9] và [82, 10]
- Sắp xếp [3, 9] n = 2
- [3] và [9] -> Hợp nhất: So sánh 3 < 9
[3, 9]
- Sắp xếp [82, 10] n = 2
- [82] và [10] -> Hợp nhất: So sánh 82 > 10
[10, 82]
- Hợp nhất [3, 9] và [10, 82] So sánh 3 < 10, 9 < 10
[3, 9, 10, 82]
- Hợp nhất [27, 38, 43] và [3, 9, 10, 82]
[3, 9, 10, 27, 38, 43, 82]
*/
#include <iostream>
using namespace std;
// 3! = 3.2.1 = 6
// Hàm tính lũy thừa n! = n.(n-1).(n-2)...1
// 0! = 1
int factorial(int n) {
  // Đệ quy: Điều kiện dừng và điều kiện đệ quy
  // Đệ quy là hàm gọi lại chính nó
  if (n == 0 || n == 1)
    return 1;                  // Điều kiện dừng
  return n * factorial(n - 1); // Điều kiện đệ quy
}
// QuickSort
void quickSort(int arr[], int left, int right) {
  // Đệ quy: Điều kiện dừng và điều kiện đệ quy
  // Điều kiện dừng: left >= right
  if (left >= right)
    return;
  // Chọn pivot là phần tử giữa
  int pivot = arr[(left + right) / 2];
  int i = left, j = right;
  // A = [12, 4, 5, 8, 3, 7]
  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) {
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }
  quickSort(arr, left, j);  // Gọi quickSort cho mảng bên trái của Pivot
  quickSort(arr, i, right); // Gọi quickSort cho mảng bên phải của Pivot
}
// MergeSort
void merge(int arr[], int left, int mid,
           int right) // Hàm hợp nhất 2 mảng con đã được sắp xếp
{
  // - VD: [38, 27, 43, 3, 9, 82, 10] left = 0, mid = n/2 = 3,5 = 3, right = 6
  // - Chia thành 2 mảng con: [38, 27, 43, 3] và [ 9, 82, 10]
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int L[n1], R[n2]; // Tạo 2 mảng con

  // Sao chép các phần tử vào 2 mảng con
  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }
  // L[3] = {38, 27, 43} và R[4] = {3, 9, 82, 10}
  //  - Hợp nhất L = [27, 38, 43i]i và R = [3, 9, 10, 82j]
  // [3, 9, 10, 27, 38, 43, 82]
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] < R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
// Hàm sắp xếp hợp nhất, dùng đệ quy

void mergeSort(int arr[], int left, int right) {
  // Bước 1: Chia mảng thành 2 nửa
  // Bước 2: Hợp nhất 2 nửa đã được sắp xếp
  if (left >= right)
    return; // Điều kiện dừng
  // limit of integer: -2^31 to 2^31 - 1 = -2147483648 to 2.147.483.647
  // left = 2 000 000 000, right = 2 000 000 001
  // left + right = 4 000 000 001 => Tràn số nguyên (overflow)
  int mid = left + (right - left) / 2; // Chia mảng
  // - VD: [38left, 27, 43, 3mid, 9, 82, 10right] left = 0, mid = n/2 = 3,5 = 3,
  // right = 6
  // - Chia thành 2 mảng con: [38, 27, 43, 3] và [9, 82, 10]
  // Chia (Divide)
  mergeSort(arr, left, mid);      // Chia mảng bên trái
  mergeSort(arr, mid + 1, right); // Chia mảng bên phải
  // Chinh phục (Conquer) - Merge (Hợp nhất)
  merge(arr, left, mid, right); // Hợp nhất 2 mảng con đã được sắp xếp
} // O(nlogn)
int main() {
  int arr[] = {12, 4, 5, 8, 3, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Mảng ban đầu: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  mergeSort(arr, 0, n - 1);
  cout << "Mảng sau khi sắp xếp: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}

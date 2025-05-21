/*
Cho dãy số nguyên A như sau:
12  2  15  -3  8  5  1  -8  6  0  4  15
1. Sắp xếp dãy trên tăng dần.
2. Suy ra số lớn thứ 3 trong dãy.
3. Suy ra số lượng phần tử lớn nhất trong dãy.
4. Sắp xếp dãy trên theo thứ tự giá trị tuyệt đối tăng dần.
5. Sắp xếp dãy trên theo quy luật sau:
• các số dương (nếu có) ở đầu mảng và có thứ tự giảm dần,
• các số âm (nếu có) ở cuối mảng và có thứ tự tăng dần.
6. Sắp xếp dãy trên theo quy luật:
• các số chẵn (nếu có) ở đầu mảng và có thứ tự tăng dần
• các số lẻ (nếu có) ở cuối mảng và có thứ tự giảm dần.
7.  Sắp xếp dãy trên theo quy luật:
• các số chẵn (nếu có) có thứ tự tăng dần,
• các số lẻ (nếu có) có thứ tự giảm dần
• tính chất chẵn/lẻ tại mỗi vị trí trong dãy A không thay đổi sau khi sắp xếp
(tức là trước khi sắp xếp, tại vị trí i của dãy A là số chẵn/lẻ thì tại vị trí i
của mảng sau khi sắp xếp cũng là số chẵn/lẻ) Ví dụ:     A = (1, 1, 2, 3, 4, 5,
6, 7) Kết quả kq = (7, 5, 2, 3, 4, 1, 6, 1).
*/
#include <iostream>
using namespace std;
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
void selectionSort(int arr[], int n) {
  int min, i, j;
  for (i = 0; i < n - 1; i++) {
    int min = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    swap(arr[i], arr[min]);
  }
}
// MergeSort - "Chia để trị" - "Merge lại các mảng đã được sắp xếp"
// 1 mảng đã được sắp xếp khi nó có 1 phần tử hoặc 0 phần tử
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1; // số lượng phần tử mảng trái
  int n2 = right - mid;    // số lượng phần tử mảng phải
  int L[100], R[100];      // mảng dự bị
  // Copy dữ liệu qua 2 mảng dự bị đó
  // L = [38, 27, 43, 3] và R = [9, 82, 10]
  // [38, 27] [43, 3]
  // [9, 82] [10]
  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = arr[mid + 1 + i];
  }
  // Gộp mảng
  int i = 0, j = 0, k = left;
  // [38, 27] [43, 3] => [38] [27] [43] [3]
  // [38i, 27i]i [43, 3j]
  // L[i] < R[j] => arr[k] = R[j];
  while (i < n1 && j < n2) {
    if (L[i] >= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }
  // Xử lý hậu
  while (i < n1) {
    arr[k++] = L[i++];
  }
  while (j < n2) {
    arr[k++] = R[j++];
  }
}
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    // merge bên trái
    mergeSort(arr, left, mid);
    // left = 0, right = mid = 3
    // mid = 0 + (3 - 0)/2 = 1
    mergeSort(arr, mid + 1, right);
    // left = mid + 1 = 4
    // right = 6
    // mid = 4 + (6 - 4)/2 = 5
    // Gộp lại
    merge(arr, left, mid, right);
  }
}
int find3rd(int arr[], int n) {
  int count = 1;
  int i = n - 1;
  while (count < 3) {
    if (arr[i] > arr[i - 1]) {
      count++;
    }
    i--;
  }
  return arr[i];
}
/*
3. Suy ra số lượng phần tử lớn nhất trong dãy.
4. Sắp xếp dãy trên theo thứ tự giá trị tuyệt đối tăng dần.
5. Sắp xếp dãy trên theo quy luật sau:
• các số dương (nếu có) ở đầu mảng và có thứ tự giảm dần,
• các số âm (nếu có) ở cuối mảng và có thứ tự tăng dần.
6. Sắp xếp dãy trên theo quy luật:
• các số chẵn (nếu có) ở đầu mảng và có thứ tự tăng dần
• các số lẻ (nếu có) ở cuối mảng và có thứ tự giảm dần.
7.  Sắp xếp dãy trên theo quy luật:
• các số chẵn (nếu có) có thứ tự tăng dần,
• các số lẻ (nếu có) có thứ tự giảm dần
*/
int countMax(int arr[], int n) {
  int max = arr[n - 1];
  int count = 1;
  int i = n - 2;
  while (arr[i] == max) {
    count++;
    i--;
  }
  //-8 -3 0 1 2 4 5 6 8 12 15 15
  return count;
}
// 4. Sắp xếp dãy trên theo thứ tự giá trị tuyệt đối tăng dần.
//  |-3| = -(-3) = 3; |3| = 3, |0| = 0
//  |x| = -x nếu x < 0; |x| = x nếu x > 0; |x| = 0 nếu x = 0
int absoluteValue(int x) {
  if (x < 0) {
    return -x;
  }
  if (x > 0) {
    return x;
  }
  return 0;
}

void sortByAbsoluteValue(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    bool flag = false;
    for (int j = 0; j < n - 1; j++) {
      if (absoluteValue(arr[j]) > absoluteValue(arr[j + 1])) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag = true;
      }
    }
    if (!flag) {
      break;
    }
  }
}
// 5. Sắp xếp dãy trên theo quy luật sau:
// • các số dương (nếu có) ở đầu mảng và có thứ tự giảm dần,
// • các số âm (nếu có) ở cuối mảng và có thứ tự tăng dần.
// -8 -3 0 1 2 4 5 6 8 12 15 15
// 15 12 8 6 5 4 2 1 0 -8 -3
void sortByPosNeg(int arr[], int n) {
  int positive[n], negative[n];
  int posCount = 0, negCount = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] >= 0) {
      positive[posCount++] = arr[i];
    } else if (arr[i] < 0) {
      negative[negCount++] = arr[i];
    }
  }
  // Dương giảm dần
  mergeSort(positive, 0, posCount - 1);
  // Âm tăng dần
  selectionSort(negative, negCount);
  for (int i = 0; i < n; i++) {
    // posCount + negCount = n
    if (i < posCount) {
      arr[i] = positive[i];
    } else {
      arr[i] = negative[i - posCount];
    }
  }
}
// 6. Sắp xếp dãy trên theo quy luật:
// • các số chẵn even (nếu có) ở đầu mảng và có thứ tự tăng dần
// • các số lẻ odd (nếu có) ở cuối mảng và có thứ tự giảm dần.
void sortByEvenOdd(int arr[], int n) {
  int evenArr[n], oddArr[n];
  int evenCount = 0, oddCount = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      evenArr[evenCount++] = arr[i];
    } else {
      oddArr[oddCount++] = arr[i];
    }
  }
  // even tăng dần - odd giảm dần
  selectionSort(evenArr, evenCount);
  mergeSort(oddArr, 0, oddCount - 1);
  for (int i = 0; i < n; i++) {
    if (i < evenCount) {
      arr[i] = evenArr[i];
    } else {
      arr[i] = oddArr[i - evenCount];
    }
  }
}
// 7.  Sắp xếp dãy trên theo quy luật:
// • các số chẵn (nếu có) có thứ tự tăng dần,
// • các số lẻ (nếu có) có thứ tự giảm dần
// • tính chất chẵn/lẻ tại mỗi vị trí trong dãy A không thay đổi sau khi sắp xếp
// (tức là trước khi sắp xếp, tại vị trí i của dãy A là số chẵn/lẻ thì tại vị
// trí i của mảng sau khi sắp xếp cũng là số chẵn/lẻ)
// Ví dụ:     A = (1, 1, 2, 3, 4, 5, 6, 7)
// Kết quả kq = (7, 5, 2, 3, 4, 1, 6, 1).
// oddArr
// evenArr
// arr[i] chẵn => arr[i] = evenArr[evenCount++]
void sortByEvenOdd1(int arr[], int n) {
  int evenArr[n], oddArr[n];
  int evenCount = 0, oddCount = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      evenArr[evenCount++] = arr[i];
    } else {
      oddArr[oddCount++] = arr[i];
    }
  }
  // even tăng dần - odd giảm dần
  selectionSort(evenArr, evenCount);
  mergeSort(oddArr, 0, oddCount - 1);
  int index1 = 0, index2 = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      arr[i] = evenArr[index1++];
    } else {
      arr[i] = oddArr[index2++];
    }
  }
}
int main() {
  int n = 12;
  int arr[n] = {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15};
  selectionSort(arr, n);
  cout << "Mảng sau khi sắp xếp là:" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << "Phần tử lớn thứ 3 trong mảng là: " << find3rd(arr, n) << endl;
  cout << "Số lượng phần tử lớn nhất trong mảng là: " << countMax(arr, n)
       << endl;

  int arr1[12];
  for (int i = 0; i < n; i++) {
    arr1[i] = arr[i];
  }

  sortByAbsoluteValue(arr1, n);
  cout << "Mảng đã sắp xếp theo giá trị tuyệt đối tăng dần là: ";
  for (int i = 0; i < n; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  sortByPosNeg(arr, n);
  cout << "Mảng đã sắp xếp theo yêu cầu câu 5 là: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  sortByEvenOdd(arr, n);
  cout << "Mảng đã sắp xếp theo yêu cầu câu 6 là: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  int A[8] = {1, 1, 2, 3, 4, 5, 6, 7};
  sortByEvenOdd1(A, 8);
  cout << "Mảng đã sắp xếp theo yêu cầu câu 7 là: ";
  for (int i = 0; i < 8; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  //(7, 5, 2, 3, 4, 1, 6, 1).
  return 0;
}

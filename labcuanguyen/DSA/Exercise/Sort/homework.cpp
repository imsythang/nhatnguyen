#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
  int min, i, j;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}
// O(n^2)
void quickSort(int arr[], int left, int right) {
  int i = left;
  int j = right;
  int pivot = arr[(left + right) / 2];
  int temp;

  do {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i <= j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  } while (i <= j);
  if (left < j) {
    quickSort(arr, left, j);
  }
  if (i < right) {
    quickSort(arr, i, right);
  }
}

int main() {
  int arr[] = {12, 4, 5, 8, 3, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Mảng ban đầu: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  selectionSort(arr, n);
  cout << "Mảng sau khi sắp xếp: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}

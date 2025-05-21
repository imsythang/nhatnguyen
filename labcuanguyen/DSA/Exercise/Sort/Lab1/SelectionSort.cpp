/*
NỘI DUNG THỰC HÀNH
Cơ bản
Sinh viên đọc kỹ phát biểu bài tập và thực hiện theo hướng dẫn:
Sử dụng các thuật toán Selection Sort, Heap Sort, Quick Sort, Merge Sort để sắp
xếp một dãy các số nguyên theo thứ tự tăng dần. Người dùng sẽ lần lượt nhập
chiều dài n và các phần tử của dãy các nguyên A từ bàn phím. Toàn bộ dãy A được
lưu trữ trong một mảng số nguyên. Lần lượt sử dụng các thuật toán Selection
Sort, Heap Sort, Quick Sort, Merge Sort để sắp xếp dãy A. Chương trình sẽ in các
kết quả sắp xếp theo từng thuật toán ra màn hình Yêu cầu
1. Biên dịch đoạn chương trình nêu trên. - Viết báo cáo
2. Tại sao trong hàm SelectionSort, vòng lặp thứ nhất có điều kiện là i < N-1?
3. Trả lời các dòng lệnh có yêu cầu ghi chú.
4. Sửa lại chương trình để nhập dãy số nguyên từ file input.txt có nội dung như
sau: 5 1 2 3 8 6 23 10 Sau đó dùng thuật toán Selection Sort sắp xếp dãy số
nguyên trên tăng dần và ghi kết quả vào file output.txt
5. Sửa hàm SelectionSort trên để sắp xếp dãy số nguyên ở câu 4 giảm dần.
*/
#include <fstream>
#include <iostream>

using namespace std;
void Swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}
/* Ghi chú: tại sao không sử dụng kí hiệu & trong hàm này?
Vì mảng a[] được truyền dưới dạng con trỏ (địa chỉ của phần tử đầu tiên)
nên việc thao tác trên a[] sẽ thay đổi trực tiếp phần tử trong mảng gốc*/
void SelectionSort(int a[], int N) {
  int min; // chỉ số phần tử nhỏ nhất trong dãy hiện hành
  for (int i = 0; i < N - 1; i++) {
    /*  Ghi chú: vòng lặp này dùng để làm gì?
        - Vòng lặp này dùng để duyệt qua từng phần tử trong mảng a[] từ đầu đến
       cuối
        - Mỗi lần lặp, nó sẽ tìm phần tử nhỏ nhất trong dãy hiện hành và hoán
       đổi với phần tử đầu tiên của dãy hiện hành.
    */
    min = i;
    for (int j = i + 1; j < N; j++) {
      /*Ghi chú: vòng lặp này dùng để làm gì?
      - Vòng lặp này dùng để tìm phần tử nhỏ nhất trong dãy hiện hành
      - Nó bắt đầu từ phần tử thứ i+1 và so sánh với phần tử nhỏ nhất hiện tại
        (min).
        */
      if (a[j] < a[min]) {
        min = j;
        /* Ghi chú: thao tác này dùng để làm gì?
        - Nếu tìm thấy phần tử nhỏ hơn, cập nhật chỉ số min là vị trí của phần
        tử min*/
      }
    }
    if (min != i) {
      Swap(a[min], a[i]);
      /* Ghi chu: thao tác này dùng để làm gì?
        Thao tác này dùng để hoán đổi phần tử nhỏ nhất với phần tử đầu tiên của
        dãy hiện hành
      */
    }
  }
}

int main() {
  int n;
  cout << "Nhap so phan tu: ";
  cin >> n;
  int arr[n];
  cout << "Nhap cac phan tu: ";
  for (int i = 0; i < n; i++) {
    cout << "Nhap phan tu thu " << i + 1 << ": ";
    cin >> arr[i];
  }
  cout << "Mang truoc khi sap xep: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  SelectionSort(arr, n);
  cout << "Mang sau khi sap xep: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

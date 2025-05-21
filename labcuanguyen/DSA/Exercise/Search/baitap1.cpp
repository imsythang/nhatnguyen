/*Bài 1. Viết chương trình nhập dữ liệu cho mảng số nguyên A[n], với 0<n<100.
Hãy tìm trong A các phần tử là số lẻ và lưu vào mảng B. Bài 2. Nhập dữ liệu và
sắp xếp mảng A[n] tăng dần. Sử dụng giải thuật tìm kiếm nhị phân để tìm phần tử
có giá trị bằng X ở trong mảng A sau đó xóa nó khỏi A nếu tìm thấy. Bài 3. Nhập
vào một chuỗi S bất kì. Đếm xem trong chuỗi S có bao nhiêu kí tự khoảng trống,
bao nhiêu kí tự số, bao nhiêu kí tự là chữ cái in hoa ? "*/

// Cấu trúc dữ liệu và giải thuật - Data Structures and Algorithms (DSA)


#include <iostream>
using namespace std;
int main() {
  int A[100], B[100];
  int n, m = 0;
  cout << "Nhập số phần tử của mảng A: ";
  cin >> n;
  if (n <= 0 || n > 100) {
    cout << "n phải thuộc khoảng (0,100)!" << endl;
    return 1;
  }
  cout << "Nhập mảng: " << endl;
  for (int i = 0; i < n; i++) {
    cout << "Nhập phần tử thứ " << i + 1 << ": ";
    cin >> A[i];
    if (A[i] % 2 != 0) {
      B[m] = A[i];
      m++;
    }
  }
  cout << "Mảng B: " << endl;
  for (int i = 0; i < m; i++) {
    cout << B[i] << " ";
  }
  cout << endl;
  // Tìm kiếm tuyến tính - Mọi mảng
  // Tìm kiếm nhị phân - Mảng đã được sắp xếp
}

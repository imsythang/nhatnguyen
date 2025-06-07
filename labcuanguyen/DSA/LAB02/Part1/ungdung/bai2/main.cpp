#include "Library.h"
#include <iostream>

using namespace std;
int main() {
  Library library;

  // Thêm sách vào thư viện
  library.InsertTail(
      new Book("C++ Programming", "John Doe", "Tech Books", 2020));
  library.InsertTail(
      new Book("Data Structures", "Jane Smith", "Tech Books", 2019));
  library.InsertTail(new Book("Algorithms", "John Doe", "Science Books", 2021));
  library.InsertTail(
      new Book("Database Systems", "Alice Johnson", "Tech Books", 2022));

  // In danh sách sách
  cout << "Danh sách sách trong thư viện:" << endl;
  library.printBooks();

  // Đếm số sách của tác giả John Doe
  int count = library.countBooksByAuthor("John Doe");
  cout << "Số sách của tác giả John Doe: " << count << endl;

  // In sách theo nhà xuất bản và năm
  cout << "Sách của nhà xuất bản 'Tech Books' vào năm 2020:"
       << library.printBooksByPublisherAndYear("Tech Books", 2020) << endl;

  return 0;
}

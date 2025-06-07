#include "Book.h"

Book::Book() : next(nullptr) {}
Book::Book(string t, string a, string p, int y) {
  title = t;
  author = a;
  publisher = p;
  year = y;
  next = nullptr;
}
Book::~Book() {
  // Destructor
  // No dynamic memory allocation, so nothing to free
}
// Getter methods
string Book::GetTitle() const { return title; }
string Book::GetAuthor() const { return author; }
string Book::GetPublisher() const { return publisher; }
int Book::GetYear() const { return year; }
Book *Book::GetNextPointer() const { return next; }

// Setter methods
void Book::SetTitle(const string &t) { title = t; }
void Book::SetAuthor(const string &a) { author = a; }
void Book::SetPublisher(const string &p) { publisher = p; }
void Book::SetYear(int y) { year = y; }
void Book::SetNextPointer(Book *n) { next = n; }

#ifndef BOOK_H
#define BOOK_H
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
class Book {
private:
  string title;
  string author;
  string publisher;
  int year;
  Book *next;

public:
  Book();
  Book(string, string, string, int);
  ~Book();
  // Getter methods
  string GetTitle() const;
  string GetAuthor() const;
  string GetPublisher() const;
  int GetYear() const;
  Book *GetNextPointer() const;

  // Setter methods
  void SetTitle(const string &t);
  void SetAuthor(const string &a);
  void SetPublisher(const string &p);
  void SetYear(int y);
  void SetNextPointer(Book *n);
};

#endif // BOOK_H

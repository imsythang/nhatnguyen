#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h" // Include the Book class header file
#include <iostream>
#include <string>
using namespace std;

class Library {
private:
  Book *head;
  Book *tail;
  int nNum;

public:
  Library();
  ~Library();

  void InsertFirst(Book *e);
  void InsertTail(Book *e);
  void printBooks();
  int countBooksByAuthor(string author);
  int printBooksByPublisherAndYear(string publisher, int year);

  int GetNumberOfBooks() const { return nNum; }
};

#endif

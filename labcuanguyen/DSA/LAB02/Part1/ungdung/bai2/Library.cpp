#include "Library.h"
#include <iostream>
using namespace std;

Library::Library() {
  this->head = nullptr;
  this->tail = nullptr;
  this->nNum = 0;
}

Library::~Library() {
  Book *current = head;
  while (current != nullptr) {
    Book *next = current->GetNextPointer();
    delete current;
    current = next;
  }
}

void Library::InsertFirst(Book *e) {
  if (this->head == nullptr)
    this->head = this->tail = e;
  else {
    e->SetNextPointer(this->head);
    this->head = e;
  }
  this->nNum++;
}

void Library::InsertTail(Book *e) {
  if (this->head == nullptr)
    this->head = this->tail = e;
  else {
    this->tail->SetNextPointer(e);
    this->tail = e;
  }
  this->nNum++;
}

void Library::printBooks() {
  Book *currentBook = this->head;
  while (currentBook != nullptr) {
    cout << "Title: " << currentBook->GetTitle() << endl;
    cout << "Author: " << currentBook->GetAuthor() << endl;
    cout << "Publisher: " << currentBook->GetPublisher() << endl;
    cout << "Year: " << currentBook->GetYear() << endl;
    cout << endl;
    currentBook = currentBook->GetNextPointer();
  }
}

int Library::countBooksByAuthor(string author) {
  int countBooks = 0;
  Book *currBook = this->head;
  while (currBook != nullptr) {
    if (currBook->GetAuthor() == author) {
      countBooks++;
    }
    currBook = currBook->GetNextPointer();
  }
  return countBooks;
}

int Library::printBooksByPublisherAndYear(string publisher, int year) {
  Book *currBook = this->head;
  int count = 0;
  while (currBook != nullptr) {
    if (currBook->GetPublisher() == publisher && currBook->GetYear() == year) {
      count++;
    }
    currBook = currBook->GetNextPointer();
  }
  return count;
}

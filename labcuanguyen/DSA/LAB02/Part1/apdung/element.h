/// File: Element.h - header
#ifndef ELEMENT_H
#define ELEMENT_H

class Element {
private:
  int data; // = value
  Element *pointer; // = next

public:
  Element();
  Element(int);
  virtual ~Element();
  int GetData() { return data; }
  void Setdata(int val) { data = val; }
  Element *Getpointer() { return pointer; }
  void Setpointer(Element *val) { pointer = val; }
};

#endif // ELEMENT_H

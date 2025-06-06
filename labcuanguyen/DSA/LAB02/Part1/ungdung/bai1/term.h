#ifndef TERM_H // if not defined
#define TERM_H

class term {
private:
  int coeff; // hệ số
  int exp; // số mũ
  term* next; // con trỏ đến phần tử tiếp theo
public:
  term(int coeff, int exp);
  virtual ~term();      // hủy bộ nhớ
  int getCoeff() const; // lấy hệ số
  int getExp() const; // lấy số mũ
  term* getNext() const; // lấy con trỏ đến phần tử tiếp theo
  void setNext(term* nextTerm); // đặt con trỏ đến phần tử tiếp theo
  void setCoeff(int coeff); // đặt hệ số
  void setExp(int exp); // đặt số mũ
};

#endif // TERM_H

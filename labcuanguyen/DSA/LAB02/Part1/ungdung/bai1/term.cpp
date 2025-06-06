#include "term.h"

term::term(int coeff, int exp)
{
  this->coeff = coeff;
  this->exp = exp;
  this->next = nullptr;
}

term::~term()
{
  // Destructor
}
int term::getCoeff() const
{
  return this->coeff;
}
int term::getExp() const
{
  return this->exp;
}
term* term::getNext() const
{
  return this->next;
}
void term::setNext(term* nextTerm)
{
  this->next = nextTerm;
}
void term::setCoeff(int coeff)
{
  this->coeff = coeff;
}
void term::setExp(int exp)
{
  this->exp = exp;
}
// End of term.cpp

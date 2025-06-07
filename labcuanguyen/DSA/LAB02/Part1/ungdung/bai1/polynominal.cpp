#include "polynominal.h"
#include <iostream>
#include <cmath>
using namespace std;
Polynominal::Polynominal() {
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}

Polynominal::~Polynominal() {
    // Destructor
}
void Polynominal::AddTermTail(term* newTerm) {
  // Check exp: số mũ, coeff: hệ số
  // Đây là danh sách giảm dần theo số mũ
  // x^3 + 3x^2 + 2x + 1
  // newTerm = -2x^2
  // x^3 + 3x^2 - 2x^2 + 2x + 1
  // x^3 + x^2 + 2x + 1
  // Thêm newTerm = x^4
  // x^4 + x^3(p1) + 2x^2(p2) + 1
  // Thêm newTerm = -2x^2
  // x^4 + x^3 + 1
  // p1 = nullptr, p2 = head
  // x^4(p2) + x^3()+ newTerm +  2x + 1
  // p2 = 4
  // p1 = 4,p2 = 3
  // p1 = 3, p2 = 1
    if(newTerm->getCoeff() == 0)
    {
        delete newTerm;
        return;
    }
    if(newTerm->getExp() > head->getExp())
    {
        newTerm->setNext(head);
        head = newTerm;
    }
    else{
        term* p1 = nullptr;
        term* p2 = head;
        while(p2 != nullptr && p2->getExp() > newTerm->getExp())
        {
            p1 = p2;
            p2 = p2->getNext();
        }
        if(p2->getExp() == newTerm->getExp())
        {
            p2->setCoeff(p2->getCoeff() + newTerm->getCoeff());
            delete newTerm;
            if(p2->getCoeff() == 0)
            {
                if(p1 != nullptr)
                {
                    p1->setNext(p2->getNext());
                }
                else
                {
                    head = p2->getNext();
                }
                delete p2;
            }
        }
        else
        {
            if(p1 == nullptr)
            {
                newTerm->setNext(head);
                head = newTerm;
            }
            else
            {
                p1->setNext(newTerm);
                newTerm->setNext(p2);
            }
        }
    }
}
void Polynominal::Print() const
{
    term* p = head;
    bool first = true;
    while(p != nullptr)
    {
       if(first == true)
       {
            cout << p->getCoeff() << "x^" << p->getExp();
            first = false;
       }
       else
       {
            if(p->getCoeff() > 0)
            {
                cout << " + " << p->getCoeff() << "x^" << p->getExp();
            }
            else if(p->getCoeff() < 0)
            {
                cout << " - " << abs(p->getCoeff()) << "x^" << p->getExp();
            }
       }
       p = p->getNext();
    }
    // -x^3 + 3x^2 - 2x
    cout << endl;
}
int Polynominal::evaluate(int x) {
    int sum = 0;
    term* p = head;
    while (p != nullptr) {
        // a^b => pow(a, b)
        sum += p->getCoeff() * pow(x, p->getExp());
        p = p->getNext();
    }
    return sum;
}
Polynominal* Polynominal::add(const Polynominal* p) const {
    Polynominal* listResult = new Polynominal();
    term* p1 = this->head;
    term* p2 = p->head;
    // x^3p1 + 3x^2p1 + 2xp1 + 1p1
    // -3x^4p2 + 2x^2p2 + 4xp2 => p2 = nullptr
    // result = -3x^4 + x^3
    while (p1 != nullptr || p2 != nullptr) {
        if (p1 == nullptr) {
            listResult->AddTermTail(new term(p2->getCoeff(), p2->getExp()));
            p2 = p2->getNext();
        } else if (p2 == nullptr) {
            listResult->AddTermTail(new term(p1->getCoeff(), p1->getExp()));
            p1 = p1->getNext();
        } else if (p1->getExp() > p2->getExp()) {
            listResult->AddTermTail(new term(p1->getCoeff(), p1->getExp()));
            p1 = p1->getNext();
        } else if (p1->getExp() < p2->getExp()) {
            listResult->AddTermTail(new term(p2->getCoeff(), p2->getExp()));
            p2 = p2->getNext();
        } else {
            int coeffSum = p1->getCoeff() + p2->getCoeff();
            if (coeffSum != 0) {
                listResult->AddTermTail(new term(coeffSum, p1->getExp()));
            }
            p1 = p1->getNext();
            p2 = p2->getNext();
        }
    }
    return listResult;
}
// Nhân hai đa thức
// (ap1 + bp1 + c)(dp2 + e + f) = ac + ad + bc + bd
// 3x^2.2x = 6x^3
Polynominal* Polynominal::multiple(const Polynominal* p) const {
    Polynominal* listResult = new Polynominal();
    term* p1 = this->head;
    term* p2 = p->head;
    // x^3p1 + 3x^2p1 + 2xp1 + 1p1
    // -3x^4p2 + 2x^2p2 + 4xp2 => p2 = nullptr
    while (p1 != nullptr) {
        p2 = p->head; // Reset p2 for each term in p1
        while (p2 != nullptr) {
            int coeffProduct = p1->getCoeff() * p2->getCoeff();
            int expSum = p1->getExp() + p2->getExp();
            listResult->AddTermTail(new term(coeffProduct, expSum));
            p2 = p2->getNext();
        }
        p1 = p1->getNext();
    }
    return listResult;
}

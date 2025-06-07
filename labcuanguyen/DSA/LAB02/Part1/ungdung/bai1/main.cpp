#include <iostream>
#include "polynominal.h"
using namespace std;
int main()
{
    Polynominal p1;
    p1.AddTermTail(new term(3, 2)); // 3x^2
    p1.AddTermTail(new term(2, 1)); // 2x
    p1.AddTermTail(new term(1, 0)); // 1

    Polynominal p2;
    p2.AddTermTail(new term(4, 3)); // 4x^3
    p2.AddTermTail(new term(-2, 2)); // -2x^2
    p2.AddTermTail(new term(5, 0)); // 5

    cout << "P1: ";
    p1.Print();
    cout << "P2: ";
    p2.Print();

    Polynominal* sum = p1.add(&p2);
    cout << "Sum: ";
    sum->Print();

    Polynominal* product = p1.multiple(&p2);
    cout << "Product: ";
    product->Print();

    delete sum;
    delete product;

    return 0;
}

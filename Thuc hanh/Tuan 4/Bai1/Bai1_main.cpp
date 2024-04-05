#include "Bai1.h"

int main()
{
    Fraction a, b;
    inputFraction(a);
    inputFraction(b);
    printFraction(a);
    printFraction(b);
    cout << "Sum of two fractions: ";
    printFraction(Sum(a, b));
    cout << "Sub of two fractions: ";
    printFraction(Sub(a, b));
    cout << "Mul of two fractions: ";
    printFraction(Mul(a, b));
    cout << "Div of two fractions: ";
    printFraction(Div(a, b));
    cout << "Fraction after reduced: " << endl;
    printFraction(reduceFraction(a));
    printFraction(reduceFraction(b));
    Fraction temp = reduceFraction(a);
    if (temp.iTuSo == a.iTuSo && temp.iMauSo == a.iMauSo)
        cout << "The first fraction is reduced" << endl;
    else
        cout << "The first fraction is not reduced" << endl;

    temp = reduceFraction(b);
    if (temp.iTuSo == b.iTuSo && temp.iMauSo == b.iMauSo)
        cout << "The second fraction is reduced" << endl;
    else
        cout << "The second fraction is not reduced" << endl;

    if (compareTwoFraction(a, b) == 1)
        cout << "The first fraction is larger" << endl;
    else if (compareTwoFraction(b, a) == 1)
        cout << "The second fraction is larger" << endl;
    else
        cout << "Two fraction is equal" << endl;

    return 0;
}
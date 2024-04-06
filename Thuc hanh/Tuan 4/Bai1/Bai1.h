#ifndef BAI1_H
#define BAI1_H

#include <iostream>

using namespace std;

struct Fraction
{
	int iTuSo;
	int iMauSo;
};
void inputFraction(Fraction &a);
void printFraction(Fraction a);
Fraction reduceFraction(Fraction a);
Fraction Sum(Fraction a, Fraction b);
Fraction Sub(Fraction a, Fraction b);
Fraction Mul(Fraction a, Fraction b);
Fraction Div(Fraction a, Fraction b);
int compareTwoFraction(Fraction a, Fraction b);

#endif
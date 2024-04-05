#include "Bai1.h"

void inputFraction(Fraction &a)
{
	char x = 0;
	cout << "Enter fraction by format a/b: ";
	cin >> a.iTuSo;
	cin >> x;
	cin >> a.iMauSo;
	while (a.iMauSo == 0)
	{
		cout << "Denominator cannot be 0, re-enter: ";
		cin >> a.iMauSo;
	}
}
void printFraction(Fraction a)
{
	cout << a.iTuSo << "/" << a.iMauSo;
	cout << endl;
}
int GCD(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

Fraction reduceFraction(Fraction a)
{
	int UCLN = GCD(a.iTuSo, a.iMauSo);
	a.iTuSo /= UCLN;
	a.iMauSo /= UCLN;
	return a;
}
Fraction Sum(Fraction a, Fraction b)
{
	Fraction tong = {0, 0};
	tong.iMauSo = a.iMauSo * b.iMauSo;
	tong.iTuSo = a.iTuSo * b.iMauSo + b.iTuSo * a.iMauSo;
	return tong;
}
Fraction Sub(Fraction a, Fraction b)
{
	Fraction hieu;
	hieu.iMauSo = a.iMauSo * b.iMauSo;
	hieu.iTuSo = a.iTuSo * b.iMauSo - b.iTuSo * a.iMauSo;
	return hieu;
}
Fraction Mul(Fraction a, Fraction b)
{
	Fraction tich;
	tich.iMauSo = a.iMauSo * b.iMauSo;
	tich.iTuSo = a.iTuSo * b.iTuSo;
	return tich;
}
Fraction Div(Fraction a, Fraction b)
{
	Fraction thuong;
	thuong.iTuSo = a.iTuSo * b.iMauSo;
	thuong.iMauSo = a.iMauSo * b.iTuSo;
	return thuong;
}
int compareTwoFraction(Fraction a, Fraction b)
{
	a.iTuSo *= b.iMauSo;
	b.iTuSo *= a.iMauSo;
	a.iMauSo *= b.iMauSo;
	b.iMauSo = a.iMauSo;
	if (a.iTuSo == b.iTuSo) // equal
		return 0;
	else if (a.iTuSo < b.iTuSo) // a < b
		return -1;
	else
		return 1;
}

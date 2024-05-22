#include <iostream>

using namespace std;

template <typename T>
struct PhanSo
{
	T tuSo;
	T mauSo;
};

template <typename T> PhanSo<T> Sum(PhanSo<T> a, PhanSo<T> b)
{
	PhanSo<T> sum;
	sum.tuSo = a.tuSo * b.mauSo + b.tuSo * a.mauSo;
	sum.mauSo = a.mauSo * b.mauSo;
	return sum;
}

template <typename T> PhanSo<T> Sub(PhanSo<T> a, PhanSo<T> b)
{
	PhanSo<T> sub;
	sub.tuSo = a.tuSo * b.mauSo - b.tuSo * a.mauSo;
	sub.mauSo = a.mauSo * b.mauSo;
	return sub;
}

template <typename T> PhanSo<T> Mul(PhanSo<T> a, PhanSo<T> b)
{
	PhanSo<T> mul;
	mul.tuSo = a.tuSo * b.tuSo;
	mul.mauSo = a.mauSo * b.mauSo;
	return mul;
}

template <typename T> PhanSo<T> Div(PhanSo<T> a, PhanSo<T> b)
{
	PhanSo<T> div;
	div.tuSo = a.tuSo * b.mauSo;
	div.mauSo = a.mauSo * b.tuSo;
	return div;
}

template <typename T> void Print(PhanSo<T> a)
{
	cout << a.tuSo << "/" << a.mauSo << endl;
}

int main()
{
	cout << "INTERGER\n";
	PhanSo<int> a, b;
	cin >> a.tuSo >> a.mauSo;
	cin >> b.tuSo >> b.mauSo;
	cout << "Sum: ";
	Print(Sum(a, b));
	cout << "Sub: :";
	Print(Sub(a, b));
	cout << "Mul: ";
	Print(Mul(a, b));
	cout << "Div: ";
	Print(Div(a, b));

	cout << "\n--------------------\nFLOAT\n";
	PhanSo<float> x, y;
	cin >> x.tuSo >> x.mauSo;
	cin >> y.tuSo >> y.mauSo;
	cout << "Sum: ";
	Print(Sum(x, y));
	cout << "Sub: :";
	Print(Sub(x, y));
	cout << "Mul: ";
	Print(Mul(x, y));
	cout << "Div: ";
	Print(Div(x, y));
	return 0;
}
#include <iostream>

using namespace std;

long mul(int a, int b, int index)
{
	if (index == 0)
		return 0;
	return a + mul(a, b, index - 1);
}
int main()
{
	int a = 0;
	int b = 0;
	int x = 0;
	int y = 0;
	cout << "enter a, b: ";
	cin >> a >> b;
	x = a;
	y = b;
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	int index = (a < b) ? a : b;
	if ((x < 0 && y > 0) || (x > 0 && y < 0))
		cout << x << " * " << y << " = -" << mul(a + b - index, index, index);
	else
		cout << x << " * " << y << " = " << mul(a + b - index, index, index);
	return 0;
}
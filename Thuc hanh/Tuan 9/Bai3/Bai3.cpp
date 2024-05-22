#include <iostream>

using namespace std;

int sumOfDigit(int n)
{
	if (n == 0)
		return 0;
	return (n % 10) + sumOfDigit(n / 10);
}
int main()
{
	int n = 0;
	cout << "enter n: ";
	cin >> n;
	if (n < 0)
		n = -n;
	cout << "Sum of digit: " << sumOfDigit(n);
	return 0;
}
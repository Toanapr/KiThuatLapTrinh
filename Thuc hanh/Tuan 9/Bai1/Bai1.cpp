#include <iostream>

using namespace std;

int countElementFrequency(int* a, int size, int element, int index)
{
	if (index == size)
		return 0;
	int temp = 0;
	if (a[index] == element)
		temp = 1;
	return temp + countElementFrequency(a, size, element, index + 1);
}

int main()
{
	int size = 0;
	cout << "Enter size of aray: ";
	cin >> size;
	int* a = new int[size];
	cout << "Enter value: " << endl;
	for (int i = 0; i < size; i++)
		cin >> a[i];
	int target = 0;
	cout << "Enter tager: ";
	cin >> target;
	cout << "The number of appearence: " << countElementFrequency(a, size, target, 0);
	return 0;
}
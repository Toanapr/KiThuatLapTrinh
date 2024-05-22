#include <iostream>

using namespace std;

template <typename DATATYPE>
void swapTwoElement(DATATYPE* arr, int i, int j, int n)
{
	DATATYPE temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
int main()
{
	cout << "INTERGER" << endl;

	int* a = new int[5];
	for (int i = 0; i < 5; i++)
		a[i] = i * 10;
	swapTwoElement(a, 2, 3, 5);
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
	delete[] a;

	cout << "\n---------------\n";
	cout << "FLOAT" << endl;

	float* b = new float[5];
	for (int i = 0; i < 5; i++)
		b[i] = i * 10.536;
	swapTwoElement(b, 2, 3, 5);
	for (int i = 0; i < 5; i++)
		cout << b[i] << " ";
	delete[] b;
	return 0;
}
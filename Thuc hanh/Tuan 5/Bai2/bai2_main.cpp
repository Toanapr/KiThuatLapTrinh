#include "bai2.h"

int main()
{
	srand(time(0));
	int** a;
	int row, col;
	inputMatrix(a, row, col);
	cout << "Matrix :" << endl;
	printMatrix(a, row, col);
	cout << endl;
	cout << "List: " << endl;
	List l = newList();
	changeMatrixtoList(l, a, row, col);
	printList(l);
	cout << endl;
	cout << "After sort: " << endl;
	sortArrayOfList(l);
	printList(l);
	fstream output;
	output.open("data.txt", ios::out);
	exportSumToFile(output, l);
	cout << endl;
	output.close();

	fstream input;
	input.open("data.txt", ios::in);
	int* b = arrayFromFile(input, row);
	cout << "The number of fibonacci numbera is : " << countFibo(b, row);
	input.close();
	delete[] b;
	deleteList(l);

	return 0;
}
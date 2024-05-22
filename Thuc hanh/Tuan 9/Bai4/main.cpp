#include "bai4.h"

int main()
{
	fstream input;
	StudentList l = newList();
	input.open("data.txt", ios::in);
	readFile(input, l);
	cout << "List: " << endl;
	printList(l);
	input.close();
	int* a = arrayOfTotalPoint(l);
	cout << "array: ";
	printArray(a, l.size);
	cout << endl;
	int max = -1;
	cout << "Max: " << findMax(a, l.size);
	delete[]a;
	deleteList(l);
	return 0;
}
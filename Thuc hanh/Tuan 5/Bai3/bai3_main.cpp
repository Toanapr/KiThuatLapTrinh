#include "bai3.h"

int main()
{
	fstream input;
	StudentList l = newList();
	input.open("data2.txt", ios::in);
	readFile(input, l);
	printList(l);
	input.close();
	return 0;
}
#include "bai3.h"

int main()
{
	fstream input;
	StudentList l = newList();
	input.open("data2.txt", ios::in);
	readFile(input, l);
	cout << "List: " << endl;
	printList(l);
	input.close();
	cout << endl << "After sort: " << endl;
	Sort(l);
	printList(l);
	cout << endl;
	cout << "Student good list: " << endl;
	StudentList good = getStudentGood(l);
	printList(good);
	deleteList(l);
	deleteList(good);
	return 0;
}
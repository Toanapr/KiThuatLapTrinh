#include "bai2.h"

int** allocateMatrix(int row, int col)
{
	int** a = new int* [row];
	for (int i = 0; i < row; i++)
		a[i] = new int[col];
	return a;
}
void inputMatrix(int**& a, int& row, int& col)
{
	cout << "enter row and col: ";
	cin >> row >> col;
	a = allocateMatrix(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = rand() % 20;
}
void printMatrix(int** a, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
List newList()
{
	List l;
	l.head = NULL;
	return l;
}
Node* newNode(int* _a, int _size)
{
	Node* temp = new Node;
	temp->a = _a;
	temp->size = _size;
	temp->next = NULL;
	return temp;
}
void addHead(List &l, Node* nodeAdd)
{
	if (l.head == NULL)
		l.head = nodeAdd;
	else
	{
		nodeAdd->next = l.head;
		l.head = nodeAdd;
	}
}
void printArray(int* a, int size)
{
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}
void printList(List l)
{
	Node* temp = l.head;
	while (temp != NULL)
	{
		printArray(temp->a, temp->size);
		temp = temp->next;
	}
}
void deleteList(List& l)
{
	while (l.head != NULL)
	{
		Node *de = l.head;
		l.head = l.head->next;
		delete[] de->a;
		delete de;
	}
	l.head = NULL;
}
void changeMatrixtoList(List& l, int** a, int row, int col)
{
	for (int i = row - 1; i >= 0; i--)
	{
		Node* temp = newNode(a[i], col);
		addHead(l, temp);
	}
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sort(int* a, int size)
{
	for (int i = 1; i < size - 2; i += 2)
	{
		for (int j = i + 2; j < size; j += 2)
		{
			if (a[i] < a[j])
				swap(&a[i], &a[j]);
			if (a[i - 1] > a[j - 1])
				swap(&a[i - 1], &a[j - 1]);
		}
	}
	if (size % 2 != 0)
		if (a[size - 1] < a[size - 3])
			swap(&a[size - 1], &a[size - 3]);
}
void sortArrayOfList(List& l)
{
	Node* temp = l.head;
	while (temp != NULL)
	{
		sort(temp->a, temp->size);
		temp = temp->next;
	}
}
int sum(int* a, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += a[i];
	return sum;
}
void exportSumToFile(fstream& output, List l)
{
	Node* temp = l.head;
	while (temp != NULL)
	{
		output << sum(temp->a, temp->size) << " ";
		temp = temp->next;
	}
}
bool isFibo(int n)
{
	if (n == 1 || n == 2)
		return true;
	int fn2 = 1;
	int fn1 = 2;
	int fn = fn1 + fn2;
	while (fn < n)
	{
		fn = fn1 + fn2;
		fn2 = fn1;
		fn1 = fn;
	}
	if (n == fn)
		return true;
	return false;
}
int *arrayFromFile(fstream& input, int size)
{
	int* a = new int[size];
	for (int i = 0; i < size; i++)
		input >> a[i];
	return a;
}
int countFibo(int* a, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (isFibo(a[i]))
			count++;
	return count;
}
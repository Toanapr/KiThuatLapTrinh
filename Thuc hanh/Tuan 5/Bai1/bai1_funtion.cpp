#include "bai1.h"

int **allocateMatrix(int row, int col)
{
	int** a = new int* [row];
	for (int i = 0; i < row; i++)
		a[i] = new int[col];
	return a;
}
void inputMatrix(int**& a, int& row, int& col)
{
	cout << "Enter row and col: ";
	cin >> row >> col;
	a = allocateMatrix(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = rand() % 20;
}
bool isSquareMatrix(int row, int col)
{
	return (row == col);
}
int sumOfMainDiagonal(int** a, int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (i == j)
				sum += a[i][j];
	return sum;
}
int sumOfSecondaryDiagonal(int** a, int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (i + j == row - 1)
				sum += a[i][j];
	return sum;
}
int** sumOfMatrix(int** a, int row, int col)
{
	int** sumMatrix = allocateMatrix(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sumMatrix[i][j] = 2 * a[i][j];
	return sumMatrix;
}
int sumElementsOfMatrix(int** a, int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += a[i][j];
	return sum;
}
bool isPrime(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}
bool isPerfectNumber(int n)
{
	int sumDivisor = 0;
	for (int i = 1; i < n; i++)
		if (n % i == 0)
			sumDivisor += i;
	if (sumDivisor == n)
		return true;
	else
		return false;
}
int** removeLastRowCol(int** a, int row, int col)
{
	int** b = allocateMatrix(row - 1, col - 1);
	for (int i = 0; i < row - 1; i++)
		for (int j = 0; j < col - 1; j++)
			b[i][j] = a[i][j];
	return b;
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
void deleteMatrix(int**& a, int row, int col)
{
	for (int i = 0; i < row; i++)
		delete a[i];
	delete a;
	a = NULL;
}
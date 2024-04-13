#include "bai1.h"

int main()
{
	int** a;
	int row, col;
	inputMatrix(a, row, col);
	cout << endl;
	printMatrix(a, row, col);
	if (isSquareMatrix(row, col))
	{
		cout << "Sum of main diagonal matrix: " << sumOfMainDiagonal(a, row, col) << endl;
		cout << "Sum of secondary diagonal matrix: " << sumOfSecondaryDiagonal(a, row, col) << endl;
	}
	cout << "Sum Matrix: " << endl;
	printMatrix(sumOfMatrix(a, row, col), row, col);
	int sumElement = sumElementsOfMatrix(a, row, col);
	cout << "Total element: " << sumElement << endl;
	if (isPrime(sumElement) && isPerfectNumber(sumElement))
		cout << "Total element is both Prime number and Perfect number" << endl;
	else if (isPrime(sumElement) && !isPerfectNumber(sumElement))
		cout << "Total element is prime" << endl;
	else if (!isPrime(sumElement) && isPerfectNumber(sumElement))
		cout << "Total element is perfect number" << endl;
	else
		cout << "Total element is not both Prime number and Perfect number" << endl;
	int **b = removeLastRowCol(a, row, col);
	printMatrix(b, row - 1, col - 1);
	deleteMatrix(a, row, col);
	deleteMatrix(b, row - 1, col - 1);
	return 0;
}
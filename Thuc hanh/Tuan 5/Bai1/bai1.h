#ifndef _BAI1_H_
#define _BAI1_H_

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int** allocateMatrix(int row, int col);
void inputMatrix(int**& a, int& row, int& col);
int sumOfMainDiagonal(int** a, int row, int col);
int sumOfSecondaryDiagonal(int** a, int row, int col);
int** sumOfMatrix(int** a, int row, int col);
int sumElementsOfMatrix(int** a, int row, int col);
bool isPrime(int n);
bool isPerfectNumber(int n);
int** removeLastRowCol(int** a, int row, int col);
void printMatrix(int** a, int row, int col);
bool isSquareMatrix(int row, int col);
void deleteMatrix(int**& a, int row, int col);

#endif
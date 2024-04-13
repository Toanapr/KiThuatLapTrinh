#ifndef _BAI2_H_
#define _BAI2_H_

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

struct Node
{
	int* a;
	int size;
	Node* next;
};
struct List
{
	Node* head;
};

int** allocateMatrix(int row, int col);
void printMatrix(int** a, int row, int col);
Node* newNode(int* a, int size);
List newList();
void changeMatrixtoList(List& l, int** a, int row, int col);
void printList(List l);
void inputMatrix(int**& a, int& row, int& col);
void sortArrayOfList(List& l);
void exportSumToFile(fstream& output, List l);
bool isFibo(int n);
int countFibo(int* a, int size);
int* arrayFromFile(fstream& input, int size);
void deleteList(List& l);


#endif
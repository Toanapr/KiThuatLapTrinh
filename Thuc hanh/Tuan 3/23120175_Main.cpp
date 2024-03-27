#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int **allocateMatrix(int row, int col)
{
    int **a = new int *[row];
    for (int i = 0; i < row; i++)
        a[i] = new int[col];
    return a;
}
int **createMatrix(int &row, int &col)
{
    cout << "Nhap so dong va so cot: ";
    cin >> row >> col;
    int **a = allocateMatrix(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            a[i][j] = rand() % 21;
    return a;
}
void printMatrix(int **a, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << setw(3) << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
bool isAscending(int **a, int size, int index, bool isRow)
{
    if (isRow == true)
    {
        for (int i = 0; i < size - 1; i++)
            if (a[index][i] > a[index][i + 1])
                return false;
    }
    else
    {
        for (int i = 0; i < size - 1; i++)
            if (a[i][index] > a[i + 1][index])
                return false;
    }
    return true;
}
void printAscending(int **a, int size, int index, bool isRow)
{
    if (isRow == true)
    {
        cout << "Dong " << index << ": ";
        for (int i = 0; i < size; i++)
            cout << a[index][i] << " ";
    }
    else
    {
        cout << "Cot " << index << ": ";
        for (int i = 0; i < size; i++)
            cout << a[i][index] << " ";
    }
    cout << endl;
}
void matrixAscending(int **a, int row, int col)
{
    for (int i = 0; i < row; i++)
        if (isAscending(a, col, i, true))
            printAscending(a, col, i, true);
    for (int i = 0; i < col; i++)
        if (isAscending(a, row, i, false))
            printAscending(a, row, i, false);
}

int **matrixTransposition(int **a, int row, int col)
{
    int **b = allocateMatrix(col, row);
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
            b[i][j] = a[j][i];
    return b;
}
int **sumMatrix(int **a, int row, int col)
{
    int **b = allocateMatrix(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            b[i][j] = 2 * a[i][j];
    return b;
}
bool isSymmetricMatrix(int **a, int row, int col)
{
    if (row != col)
        return false;
    for (int i = 0; i < row; i++)
        for (int j = i + 1; j < col; j++)
            if (a[i][j] != a[j][i])
                return false;
    return true;
}
int **deleteCol(int **a, int row, int col, int k)
{
    int **b = allocateMatrix(row, col - 1);
    cout << "Nhap so cot can xoa: ";
    cin >> k;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < k; j++)
            b[i][j] = a[i][j];
    for (int i = 0; i < row; i++)
        for (int j = k + 1; j < col; j++)
            b[i][j - 1] = a[i][j];
    return b;
}
void deleteMatrix(int **&a, int row, int col)
{
    for (int i = 0; i < row; i++)
        delete[] a[i];
    delete a;
}
int main()
{
    int row, col;
    int k;
    srand(time(0));
    int **a = createMatrix(row, col);
    printMatrix(a, row, col);
    matrixAscending(a, row, col);
    cout << endl;
    cout << "MA TRAN SAU KHI CHUYEN VI" << endl;
    int **b = matrixTransposition(a, row, col);
    printMatrix(b, col, row);
    cout << "TONG HAI MA TRAN" << endl;
    int **c = sumMatrix(a, row, col);
    printMatrix(c, row, col);
    if (isSymmetricMatrix(a, row, col))
        cout << "Ma tran doi xung" << endl;
    else
        cout << "Ma tran khong doi xung" << endl;
    cout << endl;
    int **d = deleteCol(a, row, col, k);
    printMatrix(d, row, col - 1);
    deleteMatrix(a, row, col);
    deleteMatrix(b, row, col);
    deleteMatrix(c, row, col);
    deleteMatrix(d, row, col);
    return 0;
}
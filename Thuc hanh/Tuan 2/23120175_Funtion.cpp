#include "23120175.h"

void createAndExportArray(int *&a, int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void isAscendingOrDecreasing(int *a, int n)
{
    bool isAcending = true;
    bool isDecreasing = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
            isDecreasing = false;
        if (a[i] > a[i + 1])
            isAcending = false;
    }

    if (isDecreasing == true && isAcending == false)
        cout << "Mang giam dan" << endl;
    else if (isDecreasing == false && isAcending == true)
        cout << "Mang tang dan" << endl;
    else
        cout << "Khong tang khong giam" << endl;
}
int sumArray(int *a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}
int findMax(int *a, int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
    }
    return max;
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
void Prime(int *a, int n)
{
    int countPrime = 0;
    cout << "Cac so nguyen to trong mang la: ";
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]) == true)
        {
            cout << a[i] << " ";
            countPrime++;
        }
    }
    cout << "\nSo luong so nguyen to la: " << countPrime << endl;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverseArray(int *&a, int n)
{
    for (int i = 0; i < n / 2; i++)
        swap(a[i], a[n - i - 1]);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
#include "23120175.h"

int main()
{
    int n = 0;
    int* a;
    //int* a = new int[n];
    createAndExportArray(a, n);
    cout << "Tong cac phan tu trong mang: " << sumArray(a, n) << endl;
    cout << "Phan tu lon nhat trong mang la: " << findMax(a, n) << endl;
    isAscendingOrDecreasing(a, n);
    Prime(a, n);
    cout << "Mang sau khi dao nguoc: ";
    reverseArray(a, n);
    delete[] a;
    return 0;
}
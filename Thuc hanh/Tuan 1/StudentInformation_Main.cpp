#include "StudentInformation.h"

int main()
{
    fstream input, output;
    input.open("input.txt", ios::in);
    output.open("output.txt", ios::out);
    int n = 0;
    student st[100];
    readFile(input, n, st);
    exportFile(output, st, n);
    student maxAvergage = findMaxAvergagePoint(st, n);
    cout << maxAvergage.name << " " << maxAvergage.dateOfBirth << " " << maxAvergage.mathPoint << " " << maxAvergage.literaturePoint << " " << maxAvergage.englishPoint;
    return 0;
}
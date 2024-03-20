#ifndef _StudentInformation_H_
#define _StudentInformation_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
struct student
{
    string name;
    string dateOfBirth;
    float mathPoint;
    float englishPoint;
    float literaturePoint;
};
void readFile(fstream &input, int &n, student st[]);
void exportFile(fstream &output, student st[], int n);
student findMaxAvergagePoint(student st[], int n);

#endif
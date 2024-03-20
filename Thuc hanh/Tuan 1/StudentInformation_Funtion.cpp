#include "StudentInformation.h"

bool isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 4 == 0 && year % 100 != 100)
        return true;
    return false;
}
bool isValidDate(int day, int month, int year)
{
    if (day > 31 || day < 1 || month > 12 || month < 1 || year <= 0)
        return false;
    else
    {
        if (month == 2)
        {
            if (day > 29)
                return false;
            if (day == 29 && !isLeapYear(year))
                return false;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11)
            if (day > 30)
                return false;
    }
    return true;
}

bool isValidPoint(float point)
{
    return (point <= 10) && (point >= 0);
}

void findSpace(int space[4], string s)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            space[count++] = i;
    }
}

string getName(string s, int len)
{
    return s.substr(0, len);
}
int getDate(string s, int pos, int len)
{
    return stoi(s.substr(pos, len));
}
float getPoint(string s, int pos, int len)
{
    return stof(s.substr(pos, len));
}
void readFile(fstream &input, int &n, student st[])
{
    string temp;
    int space[4];
    float math = 0, literture = 0, english = 0;
    int day = 0, month = 0, year = 0;
    string date;
    n = 0;
    while (getline(input, temp))
    {
        findSpace(space, temp);
        date = temp.substr(space[0] + 1, 10);
        day = getDate(date, 0, 2);
        month = getDate(date, 3, 2);
        year = getDate(date, 6, 4);
        math = getPoint(temp, space[1] + 1, space[2] - space[1]);
        literture = getPoint(temp, space[2] + 1, space[3] - space[2]);
        english = getPoint(temp, space[3] + 1, temp.size() - space[3] + 1);
        if (isValidDate(day, month, year) && isValidPoint(math) && isValidPoint(literture) && isValidPoint(english))
        {
            st[n].name = getName(temp, space[0]);
            st[n].dateOfBirth = date;
            st[n].mathPoint = math;
            st[n].literaturePoint = literture;
            st[n].englishPoint = english;
            n++;
        }
    }
}
void exportFile(fstream &output, student st[], int n)
{
    for (int i = 0; i < n; i++)
    {
        output << st[i].name << " " << st[i].dateOfBirth << " " << st[i].mathPoint << " " << st[i].literaturePoint << " " << st[i].englishPoint << endl;
    }
}
student findMaxAvergagePoint(student st[], int n)
{
    student Max = st[0];
    for (int i = 0; i < n; i++)
    {
        if ((st[i].mathPoint + st[i].literaturePoint + st[i].englishPoint) / 3 > (Max.englishPoint + Max.literaturePoint + Max.mathPoint) / 3)
            Max = st[i];
    }
    return Max;
}
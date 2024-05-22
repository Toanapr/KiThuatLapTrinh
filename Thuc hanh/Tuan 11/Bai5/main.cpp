#include <iostream>
#include <string>

using namespace std;

string number[] = {"khong ", "mot ", "hai ", "ba ", "bon ", "nam ", "sau ", "bay ", "tam ", "chin "};
string unit[] = {"nghin ", "trieu ", "ty "};

string readUnit(string s, int index)
{
    if (s[index] == '0' && s.size() > 1)
        return "";

    if (s[index] == '5' && s.size() > 1 && s[index - 1] != '0')
        return "lam ";

    return number[s[index] - '0'];
}

string readDozen(string s, int index)
{
    if (s[index] == '1')
    {
        return "muoi ";
    }
    if (s[index] == '0')
    {
        if (s[index + 1] == '0')
            return "";
        return "le ";
    }
    return number[s[index] - '0'] + "muoi ";
}

string readHundred(string s, int index)
{
    if (s[index + 2] == '0' && s[index + 1] == '0')
    {
        if (s[index] == '0')
            return "";
        else
            return number[s[index] - '0'] + "tram ";
    }
    return number[s[index] - '0'] + "tram ";
}

string readTriNumber(string s)
{
    return readHundred(s, 0) + readDozen(s, 1) + readUnit(s, 2);
}

void Process(string s)
{
    while (s.size() % 3 != 0)
        s = "0" + s;

    int n = s.size() / 3;
    int i = 1;
    int dem = 0;
    string res = "";

    while (i <= n)
    {

        string temp = s.substr(s.size() - i * 3, 3);
        if (i == 1 && n != 1)
            res = readTriNumber(temp) + " " + res;
        else if (i == n)
        {
            if (temp[0] == '0' && temp[1] == '0')
                res = readUnit(temp, 2) + unit[i - (2 + 3 * dem)] + res;
            else if (temp[0] == '0' && temp[1] != '0')
                res = readDozen(temp, 1) + readUnit(temp, 2) + unit[i - (2 + 3 * dem)] + res;
            else
                res = readTriNumber(temp) + unit[i - (2 + 3 * dem)] + res;
        }
        else
            res = readTriNumber(temp) + unit[i - (2 + 3 * dem)] + res;

        if (i % 4 == 0)
            dem++;

        i++;
    }
    cout << res;
}

int main()
{
    string s = "8032000703419491";
    //8 032 000 703 419 491
    string res = "";
    Process(s);
    cout << endl;
    return 0;
}
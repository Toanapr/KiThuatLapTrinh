#include <iostream>
#include <string>

using namespace std;
int Count(string s1, string s2)
{
	int index = -1;
	int cnt = 0;
	while (int(s1.find(s2, index + 1)) > 0)
	{
		cnt++;
		index = s1.find(s2, index + 1);
	}
	return cnt;
}

int main()
{
	cout << Count("hom nay troi mua to qua troi oi la troi", "troi");
	return 0;
}
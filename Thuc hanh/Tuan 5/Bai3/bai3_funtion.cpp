#include "bai3.h"

StudentList newList()
{
	StudentList l;
	l.head = NULL;
	l.size = 0;
	return l;
}
void addHead(StudentList& l, Student *nodeAdd)
{
	if (l.head == NULL)
	{
		l.head = nodeAdd;
		l.size++;
	}
	else
	{
		nodeAdd->next = l.head;
		l.head = nodeAdd;
		l.size++;
	}
}
void findSpace(int *space, string s)
{
	int cnt= 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == ' ')
			space[cnt++] = i;
}
int getAge(int day, int month, int year)
{
	int age = 2024 - year;
	if (month < 4)
		age--;
	else if (month == 4 && day < 14)
		age--;
	return age;
}
void readFile(fstream& input, StudentList& l)
{
	string temp;
	int* space = new int[5];
	while (getline(input, temp))
	{
		findSpace(space, temp);
		Student* node = new Student();
		node->name = temp.substr(0, space[0]);
		node->gender = temp.substr(space[0] + 1, space[1] - space[0] - 1);
		node->date = stoi(temp.substr(space[1] + 1, 2));
		node->month = stoi(temp.substr(space[1] + 4, 2));
		node->year = stoi(temp.substr(space[1] + 7, 4));
		node->mathScore = stoi(temp.substr(space[2] + 1, space[3] - space[2]));
		node->literatureScore = stoi(temp.substr(space[3] + 1, space[4] - space[3]));
		node->englishScore = stoi(temp.substr(space[4] + 1));
		node->averageScore = (node->mathScore + node->literatureScore + node->englishScore) / 3;
		node->age = getAge(node->date, node->month, node->year);
		addHead(l, node);
	}
}
void printStudent(Student* st)
{
	cout << st->name << " " << st->gender << " " << st->date << "/" << st->month << "/" << st->year << " " << st->mathScore << " " << st->literatureScore << " " << st->englishScore << endl;
}
void printList(StudentList l)
{
	Student* temp = l.head;
	while (temp != NULL)
	{
		printStudent(temp);
		temp = temp->next;
	}
}

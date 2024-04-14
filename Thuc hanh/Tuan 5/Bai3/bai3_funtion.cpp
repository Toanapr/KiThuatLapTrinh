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
float getRoundAverage(float n)
{
	float decimal = n - int(n);
	if (decimal >= 0 && decimal < 0.125)
		return 0;
	else if (decimal >= 0.125 && decimal < 0.25 + 0.125)
		return 0.25;
	else if (decimal >= 0.25 + 0.125 && decimal < 0.5 + 0.125)
		return 0.5;
	else if (decimal >= 0.5 + 0.125 && decimal < 0.75 + 0.125)
		return 0.75;
	else
		return 1;
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
		node->averageScore = int((node->mathScore + node->literatureScore + node->englishScore) / 3.0) + getRoundAverage((node->mathScore + node->literatureScore + node->englishScore) / 3.0);
		node->age = getAge(node->date, node->month, node->year);
		addHead(l, node);
	}
}
void printStudent(Student* st)
{
	cout << st->name << " " << st->gender << " " << st->date << "/" << st->month << "/" << st->year << " " << st->mathScore << " " << st->literatureScore << " " << st->englishScore << " " << st->averageScore << endl;
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
template <class type>
void swap_buffalo(type &a, type &b)
{
	type temp = a;
	a = b;
	b = temp;
}
void swap(Student*& a, Student*& b)
{
	swap_buffalo(a->age, b->age);
	swap_buffalo(a->name, b->name);
	swap_buffalo(a->gender, b->gender);
	swap_buffalo(a->date, b->date);
	swap_buffalo(a->month, b->month);
	swap_buffalo(a->year, b->year);
	swap_buffalo(a->mathScore, b->mathScore);
	swap_buffalo(a->literatureScore, b->literatureScore);
	swap_buffalo(a->englishScore, b->englishScore);
	swap_buffalo(a->averageScore, b->averageScore);
}
void swap(Student* prev1, Student* curr1, Student* prev2, Student* curr2)
{
	prev1->next = curr2;
	prev2->next = curr1;
	Student* temp = curr1->next;
	curr1->next = curr2->next;
	curr2->next = temp;
}
void Sort(StudentList& l)
{
	Student* add = new Student();
	addHead(l, add);

	Student* temp = l.head;
	for (Student* i = l.head; i != NULL && i->next != NULL; i = i->next)
		for (Student* j = i; j != NULL && j->next != NULL; j = j->next)
		{
			/*if (i->name > j->name)
			{
				swap(i, j);
			}
			else if (i->name == j->name && i->averageScore > j->averageScore)
			{
				swap(i, j);
			}*/
			if (i->next->name > j->next->name)
			{
				swap(i, i->next, j, j->next);
			}
			else if (i->next->name == j->next->name && i->next->averageScore > j->next->averageScore)
			{
				swap(i,i->next, j, j->next);
			}
		}

	if (l.head != NULL)
		l.head = l.head->next;
	delete add;
}
StudentList getStudentGood(StudentList l)
{
	StudentList studentGoodList = newList();
	Student* temp = l.head;
	while (temp != NULL)
	{
		if (temp->averageScore >= 8 && temp->mathScore > 7 && temp->literatureScore > 7 && temp->englishScore > 7)
		{
			Student* add = new Student(temp);
			addHead(studentGoodList, add);
		}
		temp = temp->next;
	}
	return studentGoodList;
}
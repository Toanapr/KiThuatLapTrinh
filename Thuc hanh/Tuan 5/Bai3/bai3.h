#ifndef _BAI3_H_
#define _BAI3_H_

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

struct Student 
{
	string name;
	string gender;
	int date;
	int month;
	int year;
	int age;
	int mathScore;
	int literatureScore;
	int englishScore;
	float averageScore;
	Student* next;

	Student()
	{
		name = "";
		gender = "";
		date = 0;
		month = 0;
		year = 0;
		age = 0;
		mathScore = 0;
		literatureScore = 0;
		englishScore = 0;
		averageScore = 0;
		next = NULL;
	}
	Student(Student *add)
	{
		name = add->name;
		gender = add->gender;
		date = add->date;
		month = add->month;
		year = add->year;
		age = add->age;
		mathScore = add->mathScore;
		literatureScore = add->literatureScore;
		englishScore = add->englishScore;
		averageScore = add->averageScore;
		next = NULL;
	}
};
struct StudentList
{
	Student* head;
	int size;
};

StudentList newList();
void readFile(fstream& input, StudentList& l);
void printList(StudentList l);
void Sort(StudentList& l);
StudentList getStudentGood(StudentList l);

#endif
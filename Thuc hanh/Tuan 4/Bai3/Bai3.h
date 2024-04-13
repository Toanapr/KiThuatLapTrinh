#ifndef _BAI3_H
#define _BAI3_H

#include <iostream>

using namespace std;

struct Node
{
    int score;
    Node *next;
};
struct linkList
{
    Node *head;
    int size;
};
void createList(linkList &l);
Node *createNode(int _score);
void addHead(linkList &l, Node *nodeAdd);
void addTail(linkList &l, Node *nodeAdd);
void addNode(linkList &l, Node *nodeAdd, int pos);
void deleteHead(linkList &l);
void deleteTail(linkList &l);
void deleteNode(linkList &l, int pos);
Node *findMaxScoreNode(linkList l);
float getAverageScoreList(linkList l);
void Sort(linkList &l);
void swap(int *a, int *b);
void printList(linkList l);
void deleteList(linkList &l);
#endif
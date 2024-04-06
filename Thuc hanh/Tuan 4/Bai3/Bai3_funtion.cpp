#include "Bai3.h"

void createList(linkList &l)
{
    l.head = NULL;
    l.size = 0;
}
Node *createNode(int _score)
{
    Node *temp = new Node;
    temp->score = _score;
    temp->next = NULL;
    return temp;
}
void addHead(linkList &l, Node *nodeAdd)
{
    if (l.head == NULL)
    {
        l.head = nodeAdd;
    }
    else
    {
        nodeAdd->next = l.head;
        l.head = nodeAdd;
    }
    l.size++;
}
void addTail(linkList &l, Node *nodeAdd)
{
    if (l.head == NULL)
    {
        l.head = nodeAdd;
    }
    else
    {
        Node *temp = l.head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nodeAdd;
    }
    l.size++;
}
void addNode(linkList &l, Node *nodeAdd, int pos)
{
    if (pos == 1)
        addHead(l, nodeAdd);
    else if (pos == l.size + 1)
        addTail(l, nodeAdd);
    else
    {
        Node *temp = l.head;
        int n = 0;
        while (n < pos - 2)
        {
            n++;
            temp = temp->next;
        }
        nodeAdd->next = temp->next;
        temp->next = nodeAdd;
        l.size++;
    }
}
void deleteHead(linkList &l)
{
    if (l.head == NULL)
        return;
    else
    {
        Node *de = l.head;
        l.head = l.head->next;
        l.size--;
        delete de;
    }
}
void deleteTail(linkList &l)
{
    Node *temp = l.head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *de = temp->next;
    temp->next = NULL;
    l.size--;
    delete de;
}
void deleteNode(linkList &l, int pos)
{
    if (pos == 1)
        deleteHead(l);
    else if (pos == l.size + 1)
        deleteTail(l);
    else
    {
        Node *temp = l.head;
        int n = 0;
        while (n < pos - 2)
        {
            n++;
            temp = temp->next;
        }
        Node *de = temp->next;
        temp->next = de->next;
        delete de;
        l.size--;
    }
}
Node *findMaxScoreNode(linkList l)
{
    Node *temp = l.head;
    Node *max = l.head;
    while (temp != NULL)
    {
        if (temp->score > max->score)
            max = temp;
        temp = temp->next;
    }
    return max;
}
float getAverageScoreList(linkList l)
{
    Node *temp = l.head;
    float average = 0;
    float sum = 0;
    while (temp != NULL)
    {
        sum += temp->score;
        temp = temp->next;
    }
    return sum / l.size;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Sort(linkList &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
        for (Node *j = i->next; j != NULL; j = j->next)
            if (i->score > j->score)
                swap(i->score, j->score);
}
void printList(linkList l)
{
    Node *temp = l.head;
    while (temp != NULL)
    {
        cout << temp->score << " ";
        temp = temp->next;
    }
    cout << endl;
}
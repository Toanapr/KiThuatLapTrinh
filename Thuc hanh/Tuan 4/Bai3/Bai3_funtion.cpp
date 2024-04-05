#include "Bai3.h"

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
}
void addNode(linkList &l, Node *nodeAdd, int pos)
{
    if (pos == 0)
        addHead(l, nodeAdd);
    else if (pos = l.size - 1)
        addTail(l, nodeAdd);
    else
    {
        Node *temp = l.head;
        int n = 0;
        while (n < pos - 1)
            temp = temp->next;
        nodeAdd->next = temp->next;
        temp->next = nodeAdd;
    }
}
void printList(linkList l)
{
    Node *temp = l.head;
    while (temp != NULL)
    {
        cout << l.head->score << " ";
        temp = temp->next;
    }
    cout << endl;
}

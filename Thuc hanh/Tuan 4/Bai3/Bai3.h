#include <iostream>

using namespace std;

struct Node
{
    int score;
    Node *next;
    Node(int _score)
    {
        score = _score;
        next = NULL;
    }
};
struct linkList
{
    Node *head;
    int size;
    linkList()
    {
        head = NULL;
        size = 0;
    }
};



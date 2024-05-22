#include <iostream>
#include <ctime>
#include <random>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int _data)
    {
        data = _data;
        next = NULL;
    }
};

struct NganXep
{

    Node *head;
    int size;

    NganXep()
    {
        head = NULL;
        size = 0;
    }

    void push(int data)
    {
        Node *add = new Node(data);

        if (head == NULL)
        {
            head = add;
            size++;
            return;
        }

        add->next = head;
        head = add;
        size++;
    }

    void pop()
    {
        if (head == NULL)
            return;

        Node *de = head;
        head = head->next;
        size--;
        delete de;
    }

    int top()
    {
        return head->data;
    }

    bool empty()
    {
        return (head == NULL);
    }
};

// Cau 2
NganXep generate(NganXep &nx, int n)
{
    if (n == 0)
        return nx;
    nx.push(rand() % 100);
    generate(nx, n - 1);
}

// Cau 3
void Print(Node* head)
{
    if (head == NULL)
        return;

    cout << head->data << endl;
    Print(head->next);
}

void printStack(NganXep nx)
{
    Print(nx.head);
}
// Cau 4
void deleteStack(NganXep& nx)
{
    if (nx.empty() == true)
        return;
    nx.pop();
    deleteStack(nx);
}

int main()
{
    srand(time(NULL));
    NganXep nx;
    generate(nx, 5);
    printStack(nx);
    deleteStack(nx);

    return 0;
}
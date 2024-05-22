#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node(int _data)
    {
        data = _data;
        next = NULL;
    }
};

struct HangDoi
{
    Node* head;
    int size;

    HangDoi()
    {
        head = NULL;
        size = 0;
    }

    void push(int data)
    {
        Node* add = new Node(data);

        if (head == NULL)
        {
            head = add;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = add;
    }

    int back()
    {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        return temp->data;
    }

    int front()
    {
        return head->data;
    }

    void pop()
    {
        if (head == NULL)
            return;

        Node* de = head;
        head = head->next;
        delete de;
    }

    bool empty()
    {
        return (head == NULL);
    }
};

int main()
{
    HangDoi q;

    cout << q.empty() << endl;

    q.push(2);
    q.push(5);
    q.push(9);

    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;

    q.pop();
    q.pop();

    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;

    cout << q.empty();
    q.pop();
	return 0;
}
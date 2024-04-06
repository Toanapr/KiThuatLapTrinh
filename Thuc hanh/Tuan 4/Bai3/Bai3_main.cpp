#include "Bai3.h"

int main()
{
    linkList l;
    createList(l);
    for (int i = 0; i < 5; i++)
    {
        Node *temp = createNode(i * 10);
        addHead(l, temp);
    }

    cout << "Tao mot node moi: " << endl;
    Node *node = createNode(1);
    cout << node->score << endl;

    cout << "THEM DAU: " << endl;
    addHead(l, node);
    printList(l);

    cout << "THEM CUOI: " << endl;
    Node *add = createNode(3);
    addTail(l, add);
    printList(l);

    cout << "THEM VAO VI TRI 2: " << endl;
    add = createNode(4);
    addNode(l, add, 2);
    printList(l);

    cout << "XOA DAU: " << endl;
    deleteHead(l);
    printList(l);

    cout << "XOA CUOI: " << endl;
    deleteTail(l);
    printList(l);

    cout << "XOA VI TRI 3: " << endl;
    deleteNode(l, 3);
    printList(l);

    Node *maxScore = findMaxScoreNode(l);
    cout << "Node has max score: " << maxScore->score << endl;

    cout << "Average score of list: " << getAverageScoreList(l) << endl;

    Sort(l);
    printList(l);

    return 0;
}
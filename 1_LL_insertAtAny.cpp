#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(node *&Head, int d)
{
    node *temp = new node(d);
    temp->next = Head;
    Head = temp;
}
void insertAtTail(node *&Tail, int d)
{
    node *temp = new node(d);
    Tail->next = temp;
    Tail = Tail->next;
}
void insertAtAny(node *&Head, node *&Tail, int d, int position)
{
    int cnt = 1;
    node *temp = Head;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (position == 1)
    {
        insertAtHead(Head, d);
    }
    else if (temp->next == NULL)
    {
        insertAtTail(Tail, d);
    }
    else
    {
        node *nodeToInsert = new node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
}
// printiing LL
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *n1 = new node(10);
    node *Head = n1;
    node *Tail = n1;
    print(Head);
    insertAtAny(Head,Tail, 90,2);
    print(Head);
    insertAtAny(Head, Tail, 50, 2);
    print(Head);
    insertAtAny(Head, Tail, 80, 1);
    print(Head);
    insertAtAny(Head, Tail, 70, 3);
    print(Head);
}
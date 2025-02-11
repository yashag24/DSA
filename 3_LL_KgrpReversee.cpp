

#include <iostream>
using namespace std;
class node
{
public:
    node *next;
    int data;

    // constructor
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

node *krevList(node *head, int k=1)
{
    if (head == NULL)
    {
        return head;
    }
    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if (forward != NULL)
    {
        head->next = krevList(forward, k);
    }

    return prev;
}
void insertAtHead(node *&Head, int d)
{
    node *temp = new node(d);
    temp->next = Head;
    Head = temp;
}
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

    print(Head);
    insertAtHead(Head, 2);
    print(Head);
    insertAtHead(Head, 56);
    print(Head);
    insertAtHead(Head, 1);
    print(Head);
    insertAtHead(Head, 3);
    print(Head);
    insertAtHead(Head, 9);
    print(Head);
    node *temp = krevList(Head, 3);

    print(temp);
}
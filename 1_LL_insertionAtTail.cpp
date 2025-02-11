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
void insertAtTail(node *&Tail, int d)
{
    node *temp = new node(d);
    Tail->next = temp;
    Tail=Tail->next;
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
    insertAtTail(Tail, 50);
    print(Head);
     insertAtTail(Tail, 0);
    print(Head);
}
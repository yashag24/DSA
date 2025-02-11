// insertion at head
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
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
void insertathead(node *&head, int d)
{
    // create new node
    node *temp = new node(d);
    temp->next = head;
    head = temp; // temp ka address head me gya
}
int main()
{ // created a node;
    node *n1 = new node(10);
    // cout << n1->data;

    // head pointed to node 1
    node *head = n1; // n1 ka address head me gya

    print(head);

    insertathead(head, 50);
    print(head);
}
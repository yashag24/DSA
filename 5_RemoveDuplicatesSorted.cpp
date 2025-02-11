

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

void removeduplicate(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    node *curr = head->next;
    node *prev = head;

    while (curr != NULL)
    {
        if (prev->data == curr->data)
        {
            cout << "\nNode deleted with data = " << curr->data ;
            prev->next = curr->next;
            curr = curr->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
      
    }
      cout<<endl;
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
    node *n1 = new node(4);
    node *Head = n1;

    print(Head);
    insertAtHead(Head, 3);
    print(Head);
    insertAtHead(Head, 3);
    print(Head);
    insertAtHead(Head, 3);
    print(Head);
    insertAtHead(Head, 2);
    print(Head);
    insertAtHead(Head, 2);
    print(Head);
    insertAtHead(Head, 1);
    print(Head);
    removeduplicate(Head);
    print(Head);
}
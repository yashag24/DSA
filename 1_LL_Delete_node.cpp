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

    // destructor
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "\nMemory is freed with value:-" << value;
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

void deleteNode(node *&Head, node *&Tail, int position)
{
    node *prev = NULL;
    node *curr = Head;
    int cnt = 1;
    // delete at head
    if (position == 1)
    {
        node *temp = Head;
        Head = Head->next;
        temp->next = NULL; // Set the next pointer of the old head node to NULL

        delete temp;
    }
    // delete at any position and tail
    else
    {
        while (cnt < position)
        {
            prev = curr;

            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        if (prev->next == NULL)
        {
            Tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
// printiing LL
void print(node *&head)
{
    cout << endl;
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    node *n1 = new node(10);
    node *Head = n1;
    node *Tail = n1;
    print(Head);
    insertAtAny(Head, Tail, 90, 2);
    print(Head);
    insertAtAny(Head, Tail, 50, 2);
    print(Head);
    insertAtAny(Head, Tail, 80, 1);
    print(Head);
    insertAtAny(Head, Tail, 70, 3);
    print(Head);
    deleteNode(Head, Tail, 1);
    print(Head);
    deleteNode(Head, Tail, 3);
    print(Head);
    insertAtTail(Tail, 45);
    print(Head);
}
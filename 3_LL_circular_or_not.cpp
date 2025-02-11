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

    // Desctructor
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed with value " << value << endl;
    }
};
void insertnode(node *&Head, int element, int data)
{
    if (Head == NULL)
    {
        node *temp = new node(data);

        Head = temp;
        temp->next = temp;
    }
    else
    { // assuming that element is present
        node *curr = Head;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        node *temp = new node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(node *&Head)
{
    if (Head == NULL)
    {
        cout << "Empty list.";
        return;
    }
    node *Temp = Head;
    do
    {
        cout << Head->data << " ";
        Head = Head->next;
    } while (Head != Temp);
    cout << endl;
}
void deletenode(node *&Head, int element)
{
    if (Head == NULL)
    {
        cout << "List is empty .";
        return;
    }
    else if (Head->next == Head)
    {
        node *temp = Head;
        Head->next = NULL;
        delete temp;
        Head = NULL;

        return;
    }
    node *prev = Head;
    node *curr = prev->next;

    while (curr->data != element)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    Head = prev;
    curr->next = NULL;
    delete curr;
}
bool isCircular(node *head)
{
    if (head == NULL)
    {
        return true;
    }

    node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return false;
    }
    else
        return true;
}
int main()
{
    node *Head = NULL;
    insertnode(Head, 5, 60);
    print(Head);
    insertnode(Head, 60, 99);
    print(Head);
    insertnode(Head, 60, 45);
    print(Head);
    deletenode(Head, 60);
    print(Head);
    // deletenode(Head, 45);
    // print(Head);
    // deletenode(Head, 99);
    // print(Head);
    if (isCircular(Head))
    {
        cout << "\nLinked list is circular.";
    }
    else
        cout << "\nLinked list is not circular.";
}
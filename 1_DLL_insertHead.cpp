#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insertathead(node *&Head, int data)
{
    node *temp = new node(data);
    temp->next = Head;
    Head->prev = temp;
    Head = temp;
}
void print(node *&Head)
{
    node *temp = Head;
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
    insertathead(Head, 23);
    print(Head);
}
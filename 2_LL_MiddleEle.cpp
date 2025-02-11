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
node* middlenode(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (head->next->next == NULL)
    {
        return head->next;
    }
    node *tem1 = head;
    node *tem2 = head->next;
    while (tem2 != NULL)
    {

        tem2 = tem2->next;
        if (tem2 != NULL)
        {
            tem2 = tem2->next;
        }
        tem1 = tem1->next;
    }
    return tem1;
}
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
    cout << endl;
}
int main()
{
    node *n1 = new node(10);
    node *Head = n1;
    insertathead(Head, 23);
    print(Head);

    insertathead(Head, 3);
    print(Head);

    insertathead(Head, 7);
    print(Head);

    insertathead(Head, 2);
    print(Head);

    insertathead(Head, 9);
    print(Head);
    
 node* tem = middlenode(Head);
    cout << endl
         << "Middle node is :-" << tem->data;
}
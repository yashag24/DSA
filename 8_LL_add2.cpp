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
int convert_to_int(node *head)
{
    int num = 0;
    while (head != NULL)
    {
        num = (num * 10) + (head->data);
        head=head->next;
    }
    return num;
}
int main()
{ // created a node;
    node *n1 = new node(1);

    node *head1 = n1;

    print(head1);

    insertathead(head1, 2);
    print(head1);
    insertathead(head1, 5);
    print(head1);
    insertathead(head1, 4);
    print(head1);

    node *n2 = new node(1);

    node *head2 = n2;

    print(head2);

    insertathead(head2, 2);
    print(head2);
    insertathead(head2, 8);
    print(head2);
    insertathead(head2, 4);
    print(head2);
    int a = convert_to_int(head1);
    int b = convert_to_int(head2);

    int s=a+b;

    cout<<endl<<a<<" + "<<b<<" = "<<s;
}
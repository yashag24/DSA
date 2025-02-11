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
int lengthLL(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
void checkpalindrome(node *head)
{
    int length = lengthLL(head);

    int*arr=new int[length]; 
    
    for (int i = 0; i < length; i++)
    {
        arr[i] = head->data;
        head = head->next;
    }
    int s = 0, e = length - 1;
    int a=0;
    while (s <= e)
    {
        if (arr[s] == arr[e])
        {
            s++;
            e--;
            a=1;
        }
        else
        {a=2;
            cout << "\nIt is isn't palindrome. ";
            return;
        }
    }
    cout << "\nIt is palindrome.";
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
    node *n1 = new node(1);
    // cout << n1->data;

    // head pointed to node 1
    node *head = n1; // n1 ka address head me gya

    print(head);

    insertathead(head, 50);
    print(head);
    insertathead(head, 3);
    print(head);
    insertathead(head, 50);
    print(head);
    insertathead(head, 1);
    print(head);
    // insertathead(head, 80);
    // print(head);
    // insertathead(head, 450);
    // print(head);
    // insertathead(head, 0);
    // print(head);
    checkpalindrome(head);
}
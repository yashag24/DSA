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
        cout << "Memory is freed with value " << value;
    }
};
// node length counter
int LLlength(node *&head)
{
    node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertatHead(node *&Head, int data)
{
    node *temp = new node(data);
    temp->next = Head;
    Head = temp;
    cout << "Node inserted at head with data " << data << "." << endl;
}

void insertatTail(node *&Tail, int data)
{
    node *temp = new node(data);
    temp->next = Tail->next;
    Tail->next = temp;
    cout << "Node inserted at Tail with data " << data << "." << endl;
}
void insertatAny(node *&Head, node *&Tail, int data, int position)
{
    if (position > (LLlength(Head) + 1) || position < 1)
    {
        cout << "Please enter valid position." << endl;
        return;
    }
    int cnt = 1;
    node *prev = Head;
    if (position == 1)
    {
        insertatHead(Head, data);
    }
    else if (Tail->next == NULL) // or the condition can be position == LLlength(Head)+1
    {
        insertatTail(Tail, data);
    }
    else
    {
        node *temp = new node(data);

        while (cnt < position)
        {
            prev = prev->next;
            cnt++;
        }
        temp->next = prev->next;
        prev->next = temp;
        cout << "Node with data " << data << " inserted at position " << position << "." << endl;
    }
}
void deleteatHead(node *&Head)
{
    node *tmp = Head;
    Head = Head->next;
    cout << "Node deleted at Head  i.e. Position 1." << endl;
    // tmp->next = NULL;
    // delete tmp;
}
void deleteatTail(node *&Tail, node *&Head)
{
    if (LLlength(Head) == 0)
    {
        cout << "Empty list.";
        return;
    }
    else if(LLlength (Head)==1){
        Head = Head->next;
         cout << "Node deleted at Tail i.e Position " << LLlength(Head) << "." << endl;
    }
    else
    {
        node *prev = NULL;
        node *curr = Head;
        while (curr != NULL)
        {
            prev = curr;
            curr = curr->next;
        }

        cout << "Node deleted at Tail i.e Position " << LLlength(Head) << "." << endl;
        prev->next = NULL;
        Tail = prev;
    }
    // curr->next = NULL;
    // delete curr;
}
void deleteAtany(node *&Head, node *&Tail, int pos)
{
    if (pos > LLlength(Head) + 1 || pos < 1)
    {
        cout << "Please enter valid position." << endl;
        return;
    }

    if (pos == 1)
    {
        deleteatHead(Head);
    }
    else if (Tail->next == NULL) // or the condition can be pos == LLlength(Head)+1
    {
        deleteatTail(Tail, Head);
    }
    else
    {
        int cnt = 1;
        node *prev = NULL;
        node *curr = Head;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        cout << "Node deleted at Position " << pos << "." << endl;
        prev->next = curr->next;
        // curr->next = NULL;
        // delete curr;
    }
}
void print(node *&head)
{  if (LLlength(head) == 0)
    {
        cout << "Empty list.";
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    node *node1 = new node(10);
    node *Head = node1;
    node *Tail = node1;
    int choice = 0;
    cout << "Menu:" << endl;
    cout << "Press 1 to Insert at Head\nPress 2 to Insert at Tail\nPress 3 to Insert at Any Position\n";
    cout << "Press 4 to Delete at Head\nPress 5 to Delete at Tail\nPress 6 to Delete at Any Position\nPress 7 to Display\nPress 8 to Find Lenght of SLL\nPress 9 to Exit\n";
    int a, pos;
    while (choice != 9)
    {
        cout << "\nEnter your choice:-";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data:-";
            cin >> a;
            insertatHead(Head, a);
            break;
        case 2:
            cout << "Enter the data:-";
            cin >> a;
            insertatTail(Tail, a);
            break;
        case 3:
            cout << "Enter the position:-";
            cin >> pos;
            cout << "Enter the data:-";
            cin >> a;
            insertatAny(Head, Tail, a, pos);
            break;
        case 4:
            deleteatHead(Head);
            break;
        case 5:
            deleteatTail(Tail, Head);
            break;
        case 6:
            cout << "Enter the position:-";
            cin >> pos;
            deleteAtany(Head, Tail, pos);
            break;
        case 7:
            print(Head);
            break;
        case 8:
            cout << LLlength(Head);
            break;
        case 9:
            cout << "Exiting Program.";
            break;
        default:
            cout << "Enter valid choice";
        }
    }
}
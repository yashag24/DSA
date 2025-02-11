#include <iostream>
using namespace std;
class node
{
public:
    int data;
    
    node *next;
};
node *newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int distance(node *first, node *last)
{
    int counter = 0;
    node *curr;
    curr = first;
    while (curr != last)
    {
        counter += 1;
        curr = curr->next;
    }

    return counter + 1;
}
bool detectLoop(node *head)
{
    node *temp = new node;
    node *first, *last;
    first = head;
    last = head;
    int current_length = 0;
    int prev_length = -1;
    while (current_length > prev_length && last != NULL)
    {
        prev_length = current_length;
        current_length = distance(first, last);
        last = last->next;
    }
    if (last == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    node *head = newnode(1);
    head->next = newnode(2);
    head->next->next = newnode(3);
    head->next->next->next = newnode(4);
    head->next->next->next->next = newnode(5);
    /* Create a loop for testing(5 is pointing to 3) */
    head->next->next->next->next->next = head->next->next;
    bool found = detectLoop(head);
    if (found)
        cout << "Loop Found";
    else
        cout << "No Loop Found";
    return 0;
}

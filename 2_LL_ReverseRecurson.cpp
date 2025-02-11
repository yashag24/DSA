

#include <iostream>
using namespace std;
class LinkedListNode
{
public:
    LinkedListNode *next;
    int data;

    // constructor
    LinkedListNode(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void reverse(LinkedListNode *&Head, LinkedListNode *curr, LinkedListNode *prev)
{
    if (curr == NULL)
    {
        Head = prev;
        return;
    }
    LinkedListNode *forward=curr->next;
    reverse(Head,forward,curr);
    curr->next=prev;

}
LinkedListNode *reverseLinkedList(LinkedListNode *head)
{
    LinkedListNode *prev = NULL;
    LinkedListNode *curr = head;
    reverse(head, curr, prev);
    return head;
}
void insertAtHead(LinkedListNode *&Head, int d)
{
    LinkedListNode *temp = new LinkedListNode(d);
    temp->next = Head;
    Head = temp;
}
void print(LinkedListNode *&head)
{
    LinkedListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    LinkedListNode *n1 = new LinkedListNode(10);
    LinkedListNode *Head = n1;

    print(Head);
    insertAtHead(Head, 2);
    print(Head);
    insertAtHead(Head, 56);
    print(Head);
    insertAtHead(Head, 1);
    print(Head);
    insertAtHead(Head, 3);
    print(Head);
    LinkedListNode *temp = reverseLinkedList(Head);

    print(temp);
}
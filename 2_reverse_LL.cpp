


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

LinkedListNode *reverseLinkedList(LinkedListNode *head) 
{ if(head==NULL || head->next==NULL){
    return head;
}
    LinkedListNode *prev =NULL;
   LinkedListNode *curr=head;
LinkedListNode *forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
return prev;
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
int main(){
   LinkedListNode *n1 = new LinkedListNode(10);
    LinkedListNode *Head = n1;
 
    print(Head);
    insertAtHead(Head,2);
    print(Head);
    insertAtHead(Head,56);
    print(Head);
    insertAtHead(Head,1);
    print(Head);
    insertAtHead(Head,  3);
    print(Head);
    LinkedListNode *temp =reverseLinkedList(Head);


    print(temp);
}
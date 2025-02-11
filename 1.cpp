

#include <iostream>

using namespace std;
// class Test
// {
//     public :

//     Test(); 
//     ~Test()
// {cout<<"Destructor Called";}

// };

// Test::Test()
// {
//     cout << "Constructor Called. ";
// }

// void fun()
// {
//     static Test tl;
// }

// int main()
// {

//     cout<< "Before fun () called. ";

//     fun();
//     fun();

//     cout << "After fun() called. ";

//     return 0;

// }
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
};
node*kreverse(node*head,int k){
if(head==NULL || head->next==NULL)
return head;



node*prev=NULL,*curr=head,*forward=nullptr;
while(curr!=NULL){

forward=curr->next;
curr->next=prev;
prev=curr;
curr=forward;
}


if(forward!=NULL){
    head->next=kreverse(forward,k);
}
return prev;

}
#include <iostream>
using namespace std;
static int size;
class stack
{
public:
    int data;
    stack *next;
    static int count;

    stack(int d)
    {
        data = d;
        next = NULL;
    }
    void push(int, stack *&);
    void pop( stack *&curr);
    void peek(stack *curr);
    bool isempty();
};
int stack::count = 0;
void stack::push(int d, stack *&curr)
{
    if (count >= size)
    {
        cout << "\nStack overflow.";
        return;
    }

    stack *temp = new stack(d);
temp->next=curr;
curr = temp;
    
    count++;
}
void stack::pop(stack *&curr)
{
    if (isempty())
    {
        cout << "\nStack underflow.";
        return;
    }
    cout << "\nElement deleted with data = " << curr->data;
    count--;
    curr = curr->next;
    // stack *temp = curr;
    // curr->next = NULL;
    // delete temp;
    

}
void stack::peek(stack *curr)
{
    if (count == 0)
    {
        cout << "Stack is empty.";
        return;
    }
    cout << "\n"
         << curr->data;
}
bool stack::isempty()
{
    if (count == 0)
        return true;
    return false;
}
int main()
{
    cout << "Enter size of stack:-";
    int n;
    cin >> n;
    size = n;
    cout << "Enter first data of stack:-";
    int d;
    cin >> d;
    stack *s = new stack(d);
    stack *curr = s;
    s->push(5,curr);
    s->push(9,curr);
    s->peek(curr);
     s->push(44,curr);
     s->peek(curr);
     s->pop(curr);
       s->pop(curr);
    
      s->peek(curr);



}
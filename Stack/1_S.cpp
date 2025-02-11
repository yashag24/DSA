#include <iostream>
using namespace std;
class stack
{
public:
    int *arr;
    int top;
    int size;
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int);
    void pop();
    void peek();
    bool isempty();
};
void stack::push(int ele)
{
    if (top >= size)
    {
        cout << endl
             << "Stack overflow.";
        return;
    }

    top++;
    arr[top] = ele;
    cout << "Element " << ele << " pushed in stack.";
}
bool stack::isempty()
{

    if (top == -1)
        return true;
    return false;
}
void stack::peek()
{
    if (top == -1)
    {
        cout << endl
             << "stack is empty.";
        return;
    }
    cout << endl
         << "Top element in stack = " << arr[top];
}
void stack::pop()
{
    if (top == -1)
    {
        cout << endl
             << "stack underflow.";
        return;
    }
    cout << endl
         << arr[top--] << " popped out.";
}
int main(){




}
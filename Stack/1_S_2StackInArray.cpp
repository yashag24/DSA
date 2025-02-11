#include <iostream>
using namespace std;
class stack
{
    int top1;
    int top2;
    int *arr;
    int size;

public:
    stack(int n)
    {
        size = 9;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int ele);
    void push2(int ele);
    int pop1();
    int pop2();
    // bool isempty1();
    // bool isempty2();
};

// bool stack::isempty1(){
//   if(top1==-1 && top2!= 0 ){
//     return true;

//   }
//   return false;
// }

// bool stack::isempty2(){
//   if(top1!=size-1 && top2== size ){
//     return true;

//   }
//   return false;
// }

void stack::push1(int ele)
{
    if (top2 - top1 > 1)
    {
        top1++;
        arr[top1] = ele;
    }
    else
    {
        cout << "Stack overflow";
    }
}
void stack::push2(int ele)
{
    if (top2 - top1 > 1)
    {
        top2--;
        arr[top2] = ele;
    }
    else
    {
        cout << "Stack overflow";
    }
}

int stack::pop1()
{
    if (top1 == -1)
    {
        return -1;
    }
    int ans = arr[top1];
    top1--;
    return ans;
}
int stack::pop2()
{
    if (top2 == size)
    {
        return -1;
    }
    int ans = arr[top2];
    top2++;
    return ans;
}
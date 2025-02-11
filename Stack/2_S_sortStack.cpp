#include <iostream>
#include <stack>
using namespace std;
void sortInsert(stack<int> &s, int num)
{
    if (s.empty() || s.top() < num)
    {
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    sortInsert(s, num);
    s.push(n);
}
void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    sortStack(s);
    sortInsert(s, num);
}
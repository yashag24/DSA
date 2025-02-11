#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// queue<int> reverse(queue<int> q)
// {
//     stack<int> s;
//     while (!q.empty())
//     {
//         int num = q.front();
//         q.pop();
//         s.push(num);
//     }
//     while (!s.empty())
//     {
//         int n = s.top();
//         s.pop();
//         q.push(n);
//     }
//     return q;
// }
// using recursion
void insertAtFront(queue<int> &q, int ele)
{
    if (q.empty())
    {
        q.push(ele);
        return;
    }
    int num = q.front();
    q.pop();
    insertAtFront(q, ele);
    q.push(num);
}
void reverse(queue<int> &q)
{
    if (q.empty())
        return;
    int num = q.front();
    q.pop();
    reverse(q);
    insertAtFront(q, num);
}
int main()
{
    queue<int> q;
    q.push(3);

    q.push(4);
    q.push(5);
    q.push(6);

    q.push(2);

    reverse(q);
   while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }
    int num = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(num);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();

    reverseStack(s);
    insertAtBottom(s, x);
}
int main()
{
    stack<int> s;
    s.push(3);
    s.push(5);
    s.push(6);
    cout << endl
         << "Top = " << s.top();
    reverseStack(s);
    while (!s.empty())
    {
        cout << endl
             << "Top = " << s.top();
        s.pop();
    }
}
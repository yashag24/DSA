#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> &st, int size, int count)
{
    // base case
    if (count == size / 2)
    {
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();
    count++;
    solve(st, size, count);
    st.push(num);
}
void deleteAtMiddle(stack<int> st, int N)
{
    int count = 0;

    solve(st, N, count);
}
int main()
{
    stack<int> st;
}
#include <iostream>
#include <stack>
using namespace std;
int Brackets(string s)
{
    if (s.length() & 1 == 1)
    {
        return -1;
    }
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {

                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }

    int a = 0, b = 0;
    while (!st.empty())
    {
        if (st.top() == '}')
        {
            b++;
        }
        else
        {
            a++;
        }
        st.pop();
    }
    int ans= ((a + 1) / 2) + ((b + 1) / 2);
    return ans;
}
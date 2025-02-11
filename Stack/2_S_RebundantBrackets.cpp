#include <iostream>
#include <stack>
using namespace std;
bool Rebundantbraces(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        bool isrebundant = true;
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isrebundant = false;
                    }
                    st.pop();
                }
                st.pop();
                if (isrebundant == true)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
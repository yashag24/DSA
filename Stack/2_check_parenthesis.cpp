#include <iostream>
#include <stack>
using namespace std;
bool isvalidParenthesis(string expression)
{
    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        if (ch == '{' || ch == '[' || ch == '(')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {

                char top = s.top();
                if ((top == '{' && ch == '}') || (top == '[' && ch == ']') || (top == '(' && ch == ')'))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main(){
    string s ="{([{([])}])}";

    if(isvalidParenthesis(s)){
        cout<<"true";
    }
    else
    cout<<"False";
}
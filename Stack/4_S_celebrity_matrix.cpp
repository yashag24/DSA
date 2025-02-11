#include <iostream>
#include <vector>
#include <stack>

using namespace std;
bool knows(int a, int b, vector<vector<int>>& v, int n)
{
    if(v[a][b]==1)
    return true;

    return false;
}
int celebritycheck(vector<vector<int>> v, int n)
{ // step 1 :- stack me saare elements push karo
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    // step 2:- check if a knows b then push b else push a
    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (knows(a, b, v, n))
        {
            s.push(b);
        }
        else
            s.push(a);
    }
    int candidate = s.top();
    // the top element of stack is a potential candidate to be a celebrity

    
    int zerocount = 0;

    // checking that the candidate row elements are zero
    for (int i = 0; i < n; i++)
    {
        if (v[candidate][i] == 0)
        {
            zerocount++;
        }
    }
    int onecount = 0;
    // checking that the candidate column elements are one
    for (int i = 0; i < n; i++)
    {
        if (v[i][candidate] == 1)
        {
            onecount++;
        }
    }

    if (zerocount != n || onecount != n - 1)
    {
        return -1;
    }
    return candidate;
}
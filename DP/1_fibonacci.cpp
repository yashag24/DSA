#include <bits/stdc++.h>
using namespace std;
int fibonacci1(int n)
{
    if (n <= 1)
        return n;
    return fibonacci1(n - 1) + fibonacci1(n - 2);
    // TC---->     O(2^(n-1))
    // SC---->    O(1)
}

int fibonacci2(int n, vector<int> &DP)
{
    if (n <= 1)
        return n;
    if (DP[n] != -1)
        return DP[n];

    return DP[n] = fibonacci2(n - 1, DP) + fibonacci2(n - 2, DP);

    // TC---->     O(n)
    // SC---->    O(n)
}

int fibonacci3(int n)
{

    vector<int> DP(n + 1, -1);
    DP[0] = 0;
    DP[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2];
    }
    return DP[n];
    // TC---->     O(n)
    // SC---->    O(n)
}
int fibonacci4(int n)
{
    int prev = 1;
    int prev2 = 0;
    int curri;
    for (int i = 2; i <= n; i++)
    {
        curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }
    return prev;

    // TC---->     O(n)
    // SC---->    O(1)
}
int main()
{
    /*
     *  Write your code here.
     *  Read input as specified in the question.
     *  Print output as specified in the question.
     */
    int n;
    cin >> n;

    /*     // method 1 ---- normal method(Recursive)
         cout<<fibonacci1(n);
            // TC---->     O(2^(n-1))
            // SC---->    O(1)


   //      method 2 ---- memoization (DP) ---uses extra memomry space // TOP_DOWN
         vector<int>DP(n+1,-1);
         cout<<fibonacci2(n, DP);
    // TC---->     O(n)
    // SC---->    O(n)


    //  method 3 ------tabulation (DP)     ?? BOTTOM_UP
    cout << fibonacci3(n);
    // TC---->     O(n)
    // SC---->    O(n)
    */

   
    // method 4----------Optimized code for SC

    cout << fibonacci4(n);

    // TC---->     O(n)
    // SC---->    O(1)
}
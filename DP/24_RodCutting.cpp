#include <bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
/////////////////Recursive////////////
int solve(vector<int> &price, int n, int len, int i)
{
    if (len == 0)
        return 0;
    if (i > n || len < 0)
        return -1 * 1e9;

    int npick = solve(price, n, len, i + 1);
    int pick = 0;
    if (len >= i)
        pick = price[i] + solve(price, n, len - i, i);

    return max(npick, pick);
}

int cutRod(vector<int> &price, int n)
{

    price.push_back(price[n - 1]);
    for (int i = n - 1; i > 0; i--)
    {
        price[i] = price[i - 1];
    }

    return solve(price, n, n, 1);
    // Write your code here.
}
//////////////////Memoization///////////
int solve(vector<int> &price, int n, int len, int i, vector<vector<int>> &dp)
{
    if (len == 0)
        return 0;
    if (i > n || len < 0)
        return -1 * 1e9;
    if (dp[i][len] != -1)
        return dp[i][len];
    int npick = solve(price, n, len, i + 1, dp);
    int pick = 0;
    if (len >= i)
        pick = price[i] + solve(price, n, len - i, i, dp);

    return dp[i][len] = max(npick, pick);
}

int cutRod(vector<int> &price, int n)
{

    price.push_back(price[n - 1]);
    for (int i = n - 1; i > 0; i--)
    {
        price[i] = price[i - 1];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(price, n, n, 1, dp);
    // Write your code here.
}
/////////////////////////////Tabulize///////////////

int cutRod(vector<int> &price, int n)
{

    price.push_back(price[n - 1]);
    for (int i = n - 1; i > 0; i--)
    {
        price[i] = price[i - 1];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int len = 1; len < n + 1; len++)
        {
            int pick = 0, npick = 0;
            if (i > 1)
                npick = dp[i - 1][len];
            if (len >= i)
                pick = price[i] + dp[i][len - i];

            dp[i][len] = max(pick, npick);
        }
    }
    return dp[n][n];
    // Write your code here.
}
///////////////////////Space//////////////
int cutRod(vector<int> &price, int n)
{

    price.push_back(price[n - 1]);
    for (int i = n - 1; i > 0; i--)
    {
        price[i] = price[i - 1];
    }
    vector<int> dp(n + 1, 0);

    for (int i = 1; i < n + 1; i++)
    {
        vector<int> curr(n + 1, 0);
        for (int len = 1; len < n + 1; len++)
        {
            int pick = 0, npick = 0;
            if (i > 1)
                npick = dp[len];
            if (len >= i)
                pick = price[i] + curr[len - i];

            curr[len] = max(pick, npick);
        }
        dp = curr;
    }
    return dp[n];
    // Write your code here.
}

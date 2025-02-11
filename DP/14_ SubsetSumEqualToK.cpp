#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////REcursion/////////////////
bool solve(int i, int k, vector<int> &arr)
{
    if (k == 0)
        return true;
    if (i == 0)
        return arr[0] == k;

    bool nott = solve(i - 1, k, arr);
    bool take = false;
    if (k >= arr[i])
    {
        take = solve(i - 1, k - arr[i], arr);
    }
    return nott || take;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.

    return solve(n - 1, k, arr);
}

//////////////////////////////////////////memoization/////////////

bool solve(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (i == 0)
        return arr[0] == k;
    if (dp[i][k] != -1)
        return dp[i][k];
    bool nott = solve(i - 1, k, arr, dp);
    bool take = false;
    if (k >= arr[i])
    {
        take = solve(i - 1, k - arr[i], arr, dp);
    }
    return dp[i][k] = nott | take;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}
////////////////////////////Tabulation///////////////
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool nott = dp[i - 1][j] ;
            bool take = false;
            if (k >= arr[i])
            {
                take = dp[i - 1][j-arr[i]];
           }
             dp[i][k] = nott | take;
        }
    }
    return dp[n - 1][k];
}
/////////////////Space/////////////
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
     vector<bool>dp(k + 1, 0);

    
        dp[0] = 1;
        dp[arr[0]]=1;
    for (int i = 1; i < n; i++)
    {
     vector<bool>curr(k + 1, 0);
     curr[0]=1;
        for (int j = 1; j <= k; j++)
        {   
            bool nott = dp[j] ;
            bool take = false;
            if (j >= arr[i])
            {
                take = dp[j-arr[i]];
           }
             curr[j] = nott | take;
        }
        dp=curr;
    }
    return dp[k];
}
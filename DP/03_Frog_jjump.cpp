#include <bits/stdc++.h>
using namespace std;

//////////////method 1 //////////////////////////////////--------memoization
int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int right = INT_MAX;
    int left = solve(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    if (n > 1)
        right = solve(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);

    return dp[n] = left > right ? right : left;
}
/////////////////////////////////////method2////////////-tabulation
int solve2(int n, vector<int> &heights)
{

    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(left, right);
    }

    return dp[n];
}

int solve3(int n, vector<int> &heights)
{

    int prev = 0;
    int prev2 = 0;
    int fs, ss = INT_MAX, curr;

    for (int i = 1; i <= n; i++)
    {
        fs = prev + abs(heights[i] - heights[i - 1]);
        if (i > 1)
            ss = prev2 + abs(heights[i] - heights[i - 2]);

        curr = min(fs, ss);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int frogJump(int n, vector<int> &heights)
{ // cz of 0 based indexing
    vector<int> dp(n, -1);
    return solve(n - 1, heights, dp);

    // Write your code here.
}
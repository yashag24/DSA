#include <bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
//////////////////Recursive////////
int solve(int w, vector<int> &weight, vector<int> &profit, int i)
{
    if (w == 0)
        return 0;

    if (i < 0 || w < 0)
    {
        return -1 * 1e9;
    }

    // npick
    int npick = solve(w, weight, profit, i - 1);
    // pick
    int pick = 0;
    if (weight[i] <= w)
        pick = profit[i] + solve(w - weight[i], weight, profit, i);

    return max(pick, npick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.

    return solve(w, weight, profit, n - 1);
}
//////////////////Memoized///////////////

int solve(int w, vector<int> &weight, vector<int> &profit, int i, vector<vector<int>> &dp)
{
    if (w == 0)
        return 0;

    if (i < 0 || w < 0)
    {
        return -1 * 1e9;
    }
    if (dp[i][w] != -1)
        return dp[i][w];
    // npick
    int npick = solve(w, weight, profit, i - 1, dp);
    // pick
    int pick = 0;
    if (weight[i] <= w)
        pick = profit[i] + solve(w - weight[i], weight, profit, i, dp);

    return dp[i][w] = max(pick, npick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(w, weight, profit, n - 1, dp);
}

/////////////////////////////Tabulation.....

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= w; j++)
        {

            int npick = 0;
            if (i > 0)
                npick = dp[i - 1][j];
            int pick = 0;
            if (j >= weight[i])
                pick = profit[i] + dp[i][j - weight[i]];

            dp[i][j] = max(pick, npick);
        }
    }

    return dp[n - 1][w];
}
/////////Space/////////

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int> dp(w + 1, 0);

    for (int i = 0; i < n; i++)
    {

        vector<int> curr(w + 1, 0);

        for (int j = 1; j <= w; j++)
        {

            int npick = 0;
            if (i > 0)
                npick = dp[j];
            int pick = 0;
            if (j >= weight[i])
                pick = profit[i] + curr[j - weight[i]];

            curr[j] = max(pick, npick);
        }
        dp = curr;
    }

    return dp[w];
}
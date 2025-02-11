#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}

#define MOD 1000000007

int findWaysHelper(int i, int k, int n, vector<int>& arr, vector<vector<int>>& dp)
{

    if (k < 0)
    {
        return 0;
    }


    if (i == n)
    {
        // Sum becomes equal to the target sum.
        if (k == 0)
        {
            return 1;
        }
        return 0;
    }

    // Return the value if we already have calculated.
    if (dp[i][k] != -1)
    {
        return dp[i][k];
    }

    // If we take the ith element.
    int ans = findWaysHelper(i + 1, k - arr[i], n, arr, dp);

    // If we do not take the ith element.
    ans += findWaysHelper(i + 1, k, n, arr, dp);

    // Store the answer in dp and then return.
    dp[i][k] = ans % MOD;
    return dp[i][k];
}

int findWays(vector<int>& arr, int k)
{

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWaysHelper(0, k, n, arr, dp);
}
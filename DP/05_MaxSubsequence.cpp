#include <bits/stdc++.h>
using namespace std;
///////////////simple method////////////////////
int solve(vector<int> &nums, int ind)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    int pick = nums[ind] + solve(nums, ind - 2);
    int notpick = 0 + solve(nums, ind - 1);
    return max(pick, notpick);
}
///////////memoization//////////////////////
int solve1(vector<int> &nums, vector<int> &dp, int ind)
{
    if (ind >= 0)
        if (dp[ind] != -1)
            return dp[ind];
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    int pick = nums[ind] + solve1(nums, dp, ind - 2);
    int notpick = 0 + solve1(nums, dp, ind - 1);
    return dp[ind] = max(pick, notpick);
}
////////tabulation//////////////////////
int solve(vector<int> &nums, int ind)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        int notpick = 0 + dp[i - 1];
        if (i > 1)
            pick = nums[i] + dp[i - 2];
        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
}
//////////////////////Space OPtimization/////////////////
int solve(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0], prev2 = 0;
    int curr = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i]; 
        int notpick = 0 + prev;
        if (i > 1)
            pick = nums[i] + prev2;
        curr = max(pick, notpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    int ans = solve(nums, n - 1);
    return ans;
}
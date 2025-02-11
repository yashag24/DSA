#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
//MEmoize///////////
class Solution {
public:
int solve(vector<int> &prices, int n, int i, bool Canbuy,
          vector<vector<int>> &dp,int fee)
{
    if (i == n)
        return 0;
    if (dp[i][Canbuy] != -1)
        return dp[i][Canbuy];

    int profit;

    if (Canbuy)
    {
        int p1 = -prices[i]-fee + solve(prices, n, i + 1, 0, dp,fee);
        int p2 = 0 + solve(prices, n, i + 1, 1, dp,fee);
        profit = max(p1, p2);
    }
    else
    {
        int p2 = 0 + solve(prices, n, i + 1, 0, dp,fee);
        int p1 = prices[i] + solve(prices, n, i + 1, 1, dp,fee);
        profit = max(p1, p2);
    }
    return dp[i][Canbuy]=profit;
}
int maxProfit(vector<int> &prices,int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n , vector<int>(2, -1));
    return solve(prices, n, 0, 1,dp,fee);
}
};
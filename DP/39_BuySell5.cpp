#include <bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
/////////////Memoize//////////////
class Solution
{
public:
    int solve(vector<int> &prices, int n, int i, bool Canbuy, vector<vector<int>> &dp)
    {
        if (i >= n)
            return 0;
        if (dp[i][Canbuy] != -1)
            return dp[i][Canbuy];

        int profit;

        if (Canbuy)
        {
            int p1 = -prices[i] + solve(prices, n, i + 1, 0, dp);
            int p2 = 0 + solve(prices, n, i + 1, 1, dp);
            profit = max(p1, p2);
        }
        else
        {
            int p2 = 0 + solve(prices, n, i + 1, 0, dp);
            int p1 = prices[i] + solve(prices, n, i + 2, 1, dp);
            profit = max(p1, p2);
        }
        return dp[i][Canbuy] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, n, 0, 1, dp);
    }
};
////////////////////Tabulize/////////////
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int Canbuy = 0; Canbuy <= 1; Canbuy++)
            {
                int profit;

                if (Canbuy)
                {
                    int p1 = -1 * prices[i] + dp[i + 1][0];
                    int p2 = 0 + dp[i + 1][1];
                    profit = max(p1, p2);
                }
                else
                {
                    int p2 = 0 + dp[i + 1][0];
                    int p1 = prices[i] + dp[i + 2][1];
                    profit = max(p1, p2);
                }
                dp[i][Canbuy] = profit;
            }
        }
        return dp[0][1];
    }
};
//////////////////Space////////////////////
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp2(2, 0);
        vector<int> dp1(2, 0);
        vector<int> curr(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int Canbuy = 0; Canbuy <= 1; Canbuy++)
            {
                int profit;

                if (Canbuy)
                {
                    int p1 = -1 * prices[i] + dp1[0];
                    int p2 = 0 + dp1[1];
                    profit = max(p1, p2);
                }
                else
                {
                    int p2 = 0 + dp1[0];
                    int p1 = prices[i] + dp2[1];
                    profit = max(p1, p2);
                }
                curr[Canbuy] = profit;
            }
            dp2 = dp1;
            dp1 = curr;
        }
        return dp1[1];
    }
};

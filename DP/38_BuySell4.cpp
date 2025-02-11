#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
//////////////////////REcur////////
class Solution {
public:
int solve(vector<int> &prices, int i, int n, bool Canbuy, int cap)
    {
        if (i == n || cap == 0)
            return 0;
        int profit;
        if (Canbuy)
        {
            int p1 = -prices[i] + solve(prices, i + 1, n, 0, cap);
            int p2 = 0 + solve(prices, i + 1, n, 1, cap);
            profit = max(p1, p2);
        }
        else
        {
            int s1 = prices[i] + solve(prices, i + 1, n, 1, cap - 1);
            int s2 = 0 + solve(prices, i + 1, n, 0, cap);
            profit = max(s1, s2);
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return solve(prices,0,n,1,k);
    }
};

///////////////Memoize
class Solution {
public:
 int solve(vector<int> &prices, int i, int n, bool Canbuy, int cap, vector<vector<vector<int>>> &dp)
    {
        if (i == n || cap == 0)
            return 0;
        if (dp[i][Canbuy][cap] != -1)
            return dp[i][Canbuy][cap];
        int profit;
        if (Canbuy)
        {
            int p1 = -prices[i] + solve(prices, i + 1, n, 0, cap, dp);
            int p2 = 0 + solve(prices, i + 1, n, 1, cap, dp);
            profit = max(p1, p2);
        }
        else
        {
            int s1 = prices[i] + solve(prices, i + 1, n, 1, cap - 1, dp);
            int s2 = 0 + solve(prices, i + 1, n, 0, cap, dp);
            profit = max(s1, s2);
        }
        return dp[i][Canbuy][cap] = profit;
    }
    int maxProfit(int k,vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(prices, 0, n, 1, k, dp);
    }
};

//////////////////////////Tabulize////////////////
class Solution
{
public:
    int maxProfit(int k,vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int Canbuy = 0; Canbuy <= 1; Canbuy++)
            {
                for (int Cap = 1; Cap < k+1; Cap++)
                {
                    int profit;
                    if (Canbuy)
                    {
                        int p1 = -prices[i] + dp[i + 1][0][Cap];
                        int p2 = 0 + dp[i + 1][1][Cap];
                        profit = max(p1, p2);
                    }
                    else
                    {
                        int s1 =
                            prices[i] + dp[i + 1][1][Cap - 1];
                        int s2 = 0 + dp[i + 1][0][Cap];
                        profit = max(s1, s2);
                    }
                    dp[i][Canbuy][Cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};
////////////////////////////Space
class Solution
{
public:
    int maxProfit(int k,vector<int> &prices)
    {
        int n = prices.size();
 
            vector<vector<int>>dp(2, vector<int>(k+1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            vector<vector<int>>curr(2, vector<int>(k+1, 0));
            for (int Canbuy = 0; Canbuy <= 1; Canbuy++)
            {
                for (int Cap = 1; Cap < k+1; Cap++)
                {
                    int profit;
                    if (Canbuy)
                    {
                        int p1 = -prices[i] + dp[0][Cap];
                        int p2 = 0 + dp[1][Cap];
                        profit = max(p1, p2);
                    }
                    else
                    {
                        int s1 =
                            prices[i] + dp[1][Cap - 1];
                        int s2 = 0 + dp[0][Cap];
                        profit = max(s1, s2);
                    }
                    curr[Canbuy][Cap] = profit;
                }
            }
            dp=curr;
        }
        return dp[1][k];
    }
};

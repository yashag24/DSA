#include <bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
///////////////Memo/////////////
int solve(vector<int> &prices, int n, int i, bool Canbuy,
          vector<vector<int>> &dp)
{
    if (i == n)
        return 0;
    if (dp[i][Canbuy] != -1)
        return dp[i][Canbuy];

    int profit;

    if (Canbuy)
    {
        int p1 = -1 * prices[i] + solve(prices, n, i + 1, 0, dp);
        int p2 = 0 + solve(prices, n, i + 1, 1, dp);
        profit = max(p1, p2);
    }
    else
    {
        int p2 = 0 + solve(prices, n, i + 1, 0, dp);
        int p1 = prices[i] + solve(prices, n, i + 1, 1, dp);
        profit = max(p1, p2);
    }
    return dp[i][Canbuy]=profit;
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n , vector<int>(2, -1));
    return solve(prices, n, 0, 1,dp);
}


//////////////////////////TAbulize///////////////


















////////////////////////////Space/////////////////
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2, 0);

        for (int i = n - 1; i >= 0; i--) {
            vector<int> curr(2, 0);
            for (int Canbuy = 0; Canbuy < 2; Canbuy++) {
                int profit;

                if (Canbuy) {
                    int p1 = -1 * prices[i] + dp[0];
                    int p2 = 0 + dp[1];
                    profit = max(p1, p2);
                } else {
                    int p2 = 0 + dp[0];
                    int p1 = prices[i] + dp[1];
                    profit = max(p1, p2);
                }
                curr[Canbuy] = profit;
            }
            dp = curr;
        }

        return dp[1];
    }
};

////////////////////////
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int currBuy=0,CurrNBuy=0,AheadBuy = 0 ,AheadNBuy=0; 


        
        for (int i = n - 1; i >= 0; i--) {
            
                currBuy = max(-prices[i]+AheadNBuy,0+AheadBuy);
                CurrNBuy = max(AheadNBuy,prices[i]+AheadBuy);
                AheadBuy =currBuy;
                AheadNBuy =CurrNBuy;
        }

        return AheadBuy;
    }
};
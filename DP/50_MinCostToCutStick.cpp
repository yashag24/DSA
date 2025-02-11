#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
//////////////Recur////////////////
class Solution {
public:
    int findMinimumCost(int i, int j, vector<int>& cuts) {

        if (i > j) {
            return 0;
        }

        int mini = INT_MAX;

        for (int ind = i; ind <= j; ind++) {

            int ans = cuts[j + 1] - cuts[i - 1] +
                      findMinimumCost(i, ind - 1, cuts) +
                      findMinimumCost(ind + 1, j, cuts);

            mini = min(mini, ans);
        }

        return mini;
    }
    int minCost(int n, vector<int>& cuts) 
    {
        int j = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int i = 1;
        return findMinimumCost(i, j, cuts);
    }
};
///////////////////////Memoized///////////////
class Solution {
public:
    int findMinimumCost(int i, int j, vector<int>& cuts,vector<vector<int>>&dp) {

        if (i > j) {
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mini = INT_MAX;

        for (int ind = i; ind <= j; ind++) {

            int ans = cuts[j + 1] - cuts[i - 1] +
                      findMinimumCost(i, ind - 1, cuts,dp) +
                      findMinimumCost(ind + 1, j, cuts,dp);

            mini = min(mini, ans);
        }

        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) 
    {   
        int j = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int i = 1;
        vector<vector<int>>dp(j+1,vector<int>(j+1,-1));
        return findMinimumCost(i, j, cuts,dp);
    }
};
///////////////////////Tabulized//////////////////
class Solution {
public:
 
    int minCost(int n, vector<int>& cuts) 
    {   
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));

        for(int i = c;i>=1;i--)
        {
            for(int j =1;j<=c;j++)
            {
                if(i>j)continue;

                int mini = 1e9;
                for(int k = i;k<=j;k++)
                {
                    int curr = cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j]; 
                    mini = min(curr,mini);
                }
                dp[i][j]=mini;

            }
        }
        return dp[1][c];
    }
};

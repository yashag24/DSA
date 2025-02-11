#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
////////////////REcur

// Helper function for solving the problem recursively
int solve(vector<int> &num, int x, int i) {
    // Base cases
    if (x == 0) {
        return 0; 
    }
    if (i == 0) {
              if (x % num[0] == 0) {
            return x / num[0];
        }
        return INT_MAX; 
    }

    int notTake = solve(num, x, i - 1);

    
    int take = INT_MAX;
    if (x >= num[i]) {
       int res = solve(num, x - num[i], i);
       if(res!=INT_MAX)
       take = 1+res;
    }
    return min(notTake, take);
}

int minimumElements(vector<int> &num, int x) {
    int n = num.size();
    int ans = solve(num, x, n - 1);

    // If ans is INT_MAX, it means the target can't be achieved
    return (ans == INT_MAX) ? -1 : ans;
}

////////////////////Memoize////////////

// Helper function for solving the problem recursively
int solve(vector<int> &num, int x, int i,vector<vector<int>>&dp) {
    // Base cases
    if (x == 0) {
        return 0; 
    }
    
    if (i == 0) {
              if (x % num[0] == 0) {
            return x / num[0];
        }
        return INT_MAX; 
    }
    if(dp[i][x]!=-1)
        return dp[i][x];

    int notTake = solve(num, x, i - 1,dp);

    
    int take = INT_MAX;
    if (x >= num[i]) {
       int res = solve(num, x - num[i], i,dp);
       if(res!=INT_MAX)
       take = 1+res;
    }
    return dp[i][x]=min(notTake, take);
}

int minimumElements(vector<int> &num, int x) {
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
    int ans = solve(num, x, n - 1,dp);

    // If ans is INT_MAX, it means the target can't be achieved
    return (ans == INT_MAX) ? -1 : ans;
}
////////////////////Tabulize

int minimumElements(vector<int> &num, int x) 
{
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    
    for(int t =0;t<=x;t++){
        if(t%num[0]==0)
            dp[0][t]=t/num[0];
        else
            dp[0][t]=INT_MAX;
    }
    
    for(int i =1;i<n;i++)
    {
        for(int t= 0 ;t<=x;t++)
        {
            int notTake = dp[i-1][t];

            int take = INT_MAX;
            if (t >= num[i]) {
              int res = dp[i][t - num[i]];
              if (res != INT_MAX)
                take = 1 + res;
            }
            
            dp[i][t] = min(notTake, take);
        }
    }
    
    return dp[n-1][x]==INT_MAX?-1:dp[n-1][x];
}
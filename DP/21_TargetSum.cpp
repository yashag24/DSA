#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
//////////////////memoization///////////
const int mod = 1e9 + 7;

int solve(int n, int target, vector<int>& arr, int i, vector<vector<int>>& dp) {

     if (i == 0) {
        if (target == 0 && arr[0] == 0)
            return 2; 
        if (target == 0 || target == arr[0])
            return 1; 
        return 0;
        
    }
    
    if (dp[i][target] != -1)
        return dp[i][target];
    
    int npick = solve(n, target, arr, i - 1, dp);
    int pick = 0;
    
    if (arr[i] <= target)
        pick = solve(n, target - arr[i], arr, i - 1, dp);
    
    return dp[i][target] = (pick + npick) % mod;
}

int targetSum(int n, int target, vector<int>& arr) {
    int tsum = accumulate(arr.begin(), arr.end(), 0);
    
    if ((tsum - target) < 0 || (tsum - target) % 2 != 0)
        return 0;
    
    int newTarget = (tsum - target) / 2;
    vector<vector<int>> dp(n, vector<int>(newTarget + 1, -1));
    
    return solve(n, newTarget, arr, n - 1, dp);
}
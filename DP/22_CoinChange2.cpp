#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
///////////////////////////Recursion///////////////
long solve(int *denominations, int n, int value, int i) {
  if (value == 0)
    return 1;

  if (i < 0) {
    return 0;
  }

  // npick
  long int npick = solve(denominations, n, value, i - 1);
  // pick
  long int pick = 0;
  if (denominations[i] <= value)
    pick = solve(denominations, n, value - denominations[i], i);

  return pick + npick;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
  long int cnt = solve(denominations, n, value, n - 1);

  return cnt;
  // Write your code here
}
//////////////////////////////////Memoization////////////////////////////////
#include<bits/stdc++.h>

long solve(int *denominations, int n, int value, int i,vector<vector<long int>>&dp) {
  if (value == 0)
    return 1;

  if (i < 0) {
    return 0;
  }
  if(dp[i][value]!=-1)
    return dp[i][value];

  // npick
  long int npick = solve(denominations, n, value, i - 1,dp);
  // pick
  long int pick = 0;
  if (denominations[i] <= value)
    pick = solve(denominations, n, value - denominations[i], i,dp);

  return dp[i][value]=pick + npick;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
  vector<vector<long int>>dp(n,vector<long int>(value+1,-1));
  long int cnt = solve(denominations, n, value, n - 1,dp);

  return cnt;
  // Write your code here
}
////////////////////////////////////////////Tabulation////////////////
long countWaysToMakeChange(int *denominations, int n, int value) {
  vector<vector<long int>> dp(n, vector<long int>(value + 1, 0));

  for (int i = 0; i < n; i++) {
    dp[i][0] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= value; j++) {

      long npick = 0, pick = 0;

      if (i > 0)
        npick = dp[i - 1][j];

      if (j >= denominations[i])
        pick = dp[i][j - denominations[i]];

      dp[i][j] = pick + npick;
    }
  }

  return dp[n - 1][value];
  // Write your code here
}
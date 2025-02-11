/*You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, 
which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from 
point ‘A’ to point ‘B’.In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’,
 your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step.For example in a given point MATRIX[i][j], 
you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1]
*/
#include <bits/stdc++.h>
 using namespace std;
////////////////////////////////////normal///////////////////////////
#include <bits/stdc++.h>
int solve(int m, int n)
{
  if (m < 0 || n < 0)
    return 0;
  if (m == 0 && n == 0)
    return 1;

  int up = solve(m - 1, n);
  int left = solve(m, n - 1);
  return left + up;
}
int uniquePaths(int m, int n)
{
  // Write your code here.
  return solve(m - 1, n - 1);
}
// TC =O(2^(m*n))
// SC= O(m+n-2)
///////////////////////memoization////////////////////
#include <bits/stdc++.h>
int solve(int m, int n, vector<vector<int>> &dp)
{
  if (m < 0 || n < 0)
    return 0;
  if (dp[m][n] != -1)
    return dp[m][n];
  if (m == 0 && n == 0)
    return dp[m][n] = 1;

  int up = solve(m - 1, n, dp);
  int left = solve(m, n - 1, dp);
  return dp[m][n] = left + up;
}
int uniquePaths(int m, int n)
{
  vector<vector<int>> dp(m, vector<int>(n, -1));
  // Write your code here.
  return solve(m - 1, n - 1, dp);
}

///////////////////////////////Tabulation/////////////////////
int solve(int m, int n)
{
  vector<vector<int>> dp(m, vector<int>(n, -1));
  dp[0][0] = 1;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == 0 && j == 0)
        continue;
      int down = 0, right = 0;
      if (i > 0)
        down = dp[i - 1][j];
      if (j > 0)
        right = dp[i][j - 1];

      dp[i][j] = right + down;
    }
  }

  return dp[m - 1][n - 1];
}
int uniquePaths(int m, int n)
{

  // Write your code here.
  return solve(m, n);
}
// TC =O(m*n)
// SC= O(m*n)
///////////////////////////////space/////////////////////////////
int solve(int m , int n){
  //vector<vector<int>>dp(m,vector<int>(n,-1));
  vector<int>dp(n,0);
  dp[0]=1;
for (int i = 0; i < m; i++)
  {
    vector<int>curr(n,0);
    for (int j = 0; j < n; j++)
    {
      if (i == 0 && j == 0){
        curr[j]=1;
        continue;
      }
      int down = 0, right = 0;

        down = dp[j];
      if (j > 0)
        right = curr[j - 1];

      curr[j] = right + down;
    }
    dp=curr;
  }

  return dp[n - 1];
}

int uniquePaths(int m, int n) {

  return solve(m, n);
}

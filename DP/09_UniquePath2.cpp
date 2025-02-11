#include<bits/stdc++.h>
using namespace std;
////////////////////////////////////REcursion///////////////////
int solve(int row, int col, vector<vector<int>> &mat) {
  if (row < 0 || col < 0)
    return 0;
  if (row == 0 && col == 0)
    return 1;
  int up = 0, left = 0;
  if (row > 0)
    if (mat[row - 1][col] == 0)
      up = solve(row - 1, col, mat);

  if (col > 0)
    if (mat[row][col - 1] == 0)
      left = solve(row, col - 1, mat);

  return up + left;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
  return solve(n - 1, m - 1, mat);
}
///////////////////////////Memoization////////////
int solve(int row, int col, vector<vector<int>> &mat, vector<vector<int>>& dp) {
    int mod = 1e9 + 7;
    // Check if the cell is out of bounds or is an obstacle
    if (row < 0 || col < 0 )
        return 0;
    if(mat[row][col]==-1)
    return 0;    
    if (dp[row][col] != -1)
        return dp[row][col];

    if (row == 0 && col == 0)
        return 1;

    int up = solve(row - 1, col, mat, dp);
    int left = solve(row, col - 1, mat, dp);

    return dp[row][col] = (up + left)%mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>>dp(n,vector<int>(m,-1));
    dp[0][0]=1;
  return solve(n - 1, m - 1, mat,dp);
}
/////////////////////////////////Tabulation//////////////////////
int solve(int n, int m, vector<vector<int>> &mat) {
    // Check if the cell is out of bounds or is an obstacle
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int mod = 1e9 + 7;
    for(int i =0;i<n;i++){

        for(int j=0;j<m;j++){

            if(j==0&&i==0)
            dp[i][j]=1;
            else if(mat[i][j]==-1)
            dp[i][j]= 0;
            else{
                int up=0,left=0;
                if(i>0)
                up=dp[i-1][j];
                if(j>0)
                left = dp[i][j-1];

                dp[i][j]=(up+left)%mod;
            }
        }

    }

    return dp[n-1][m-1];    
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
;
  return solve(n , m, mat);
}

////////////////////////Space////////////////////

int solve(int n, int m, vector<vector<int>> &mat) {
  // Check if the cell is out of bounds or is an obstacle
  vector<int> dp(m, 0);
  dp[0]=1;
  int mod = 1e9 + 7;
  for (int i = 0; i < n; i++) {
    vector<int>temp(m,0);
    for (int j = 0; j < m; j++) {

      if (j == 0 && i == 0)
        temp[j] = 1;
      else if (mat[i][j] == -1)
        dp[j] = 0;
      else {
        int up = 0, left = 0;
        if (i > 0)
          up = dp[j];
        if (j > 0)
          left = temp[j - 1];

        temp[j] = (up + left) % mod;
      }
    }
    dp=temp;
  }

  return dp[m - 1];
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
;
  return solve(n , m, mat);
}

 
#include<bits/stdc++.h>
using namespace std;
//////////////////////////////simple//////////////////////////////
int solve(int srci, int n, int m, int srcj, vector<vector<int>> &matrix) {
  if (srcj < 0 || srcj >= m)
    return -1e9;
  if (srci == 0)
    return matrix[srci][srcj];

  int up = matrix[srci][srcj] + solve(srci - 1, n, m, srcj + 0, matrix);
  int leftup = matrix[srci][srcj] + solve(srci - 1, n, m, srcj - 1, matrix);
  int rightup = matrix[srci][srcj] + solve(srci - 1, n, m, srcj + 1, matrix);

  return max(up, max(leftup, rightup));
}
int getMaxPathSum(vector<vector<int>> &matrix) {
  //  Write your code here.
  int n = matrix.size();
  int m = matrix[0].size();
  int ans = INT_MIN;

  for (int i = 0; i < m; i++) {
    ans = max(ans, solve(n - 1, n, m, i, matrix));
  }
  return ans;
}
////////////////////////////////////////memoization/////////////////////////////////
#include <bits/stdc++.h>
int solve(int srci, int n, int m, int srcj, vector<vector<int>> &matrix,vector<vector<int>>&dp) {
  if (srcj < 0 || srcj >= m)
    return -1e9;

  if(dp[srci][srcj]!=-1)
  return dp[srci][srcj];  
  if (srci == 0)
    return dp[srci][srcj]=matrix[srci][srcj];

  int up = matrix[srci][srcj] + solve(srci - 1, n, m, srcj + 0, matrix,dp);
  int leftup = matrix[srci][srcj] + solve(srci - 1, n, m, srcj - 1, matrix,dp);
  int rightup = matrix[srci][srcj] + solve(srci - 1, n, m, srcj + 1, matrix,dp);

  return dp[srci][srcj] = max(up, max(leftup, rightup));
}
int getMaxPathSum(vector<vector<int>> &matrix) {
  //  Write your code here.
  int n = matrix.size();
  int m = matrix[0].size();
  int ans = INT_MIN;
vector<vector<int>>dp(n,vector<int>(m,-1));
  for (int i = 0; i < m; i++) {
    ans = max(ans, solve(n - 1, n, m, i, matrix,dp));
  }
  return ans;
}

/////////////////////////////////////////tabulation////////////////////////

int getMaxPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(); // Number of rows in the matrix
    int m = matrix[0].size(); // Number of columns in the matrix

    // Create a 2D DP (dynamic programming) array to store maximum path sums
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize the first row of dp with values from the matrix (base condition)
    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }

    // Iterate through the matrix rows starting from the second row
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Calculate the maximum path sum for the current cell considering three possible directions: up, left diagonal, and right diagonal

            // Up direction
            int up = matrix[i][j] + dp[i - 1][j];

            // Left diagonal direction (if it's a valid move)
            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0) {
                leftDiagonal += dp[i - 1][j - 1];
            } else {
                leftDiagonal += -1e9; // A very large negative value to represent an invalid path
            }

            // Right diagonal direction (if it's a valid move)
            int rightDiagonal = matrix[i][j];
            if (j + 1 < m) {
                rightDiagonal += dp[i - 1][j + 1];
            } else {
                rightDiagonal += -1e9; // A very large negative value to represent an invalid path
            }

            // Store the maximum of the three paths in dp
            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    // Find the maximum value in the last row of dp, which represents the maximum path sums ending at each cell
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, dp[n - 1][j]);
    }

    // The maximum path sum is the maximum value in the last row
    return maxi;
}
/////////////////////////////////////////Space Optimization/////////////////////////////

int getMaxPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(); // Number of rows in the matrix
    int m = matrix[0].size(); // Number of columns in the matrix

    
    vector<int> dp(m, 0);

    
    for (int j = 0; j < m; j++) {
        dp[j] = matrix[0][j];
    }

    // Iterate through the matrix rows starting from the second row
    for (int i = 1; i < n; i++) {
      vector<int>temp(m,0);
        for (int j = 0; j < m; j++) {
            // Calculate the maximum path sum for the current cell considering three possible directions: up, left diagonal, and right diagonal

            // Up direction
            int up = matrix[i][j] + dp[j];

            // Left diagonal direction (if it's a valid move)
            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0) {
                leftDiagonal += dp[j - 1];
            } else {
                leftDiagonal += -1e9; // A very large negative value to represent an invalid path
            }

            // Right diagonal direction (if it's a valid move)
            int rightDiagonal = matrix[i][j];
            if (j + 1 < m) {
                rightDiagonal += dp[j + 1];
            } else {
                rightDiagonal += -1e9; // A very large negative value to represent an invalid path
            }

            // Store the maximum of the three paths in dp
            temp[j] = max(up, max(leftDiagonal, rightDiagonal));
        }
        dp=temp;
    }

    // Find the maximum value in the last row of dp, which represents the maximum path sums ending at each cell
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, dp[j]);
    }

    // The maximum path sum is the maximum value in the last row
    return maxi;
}
#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////SIMPLE//////////////////////////////
int solve(int row, int col1,int col2, vector<vector<int>> &grid, int n, int m) {
  if (row == n - 1) {

    if (col1 == col2)
      return grid[row][col1];

    return grid[row][col1] + grid[row][col2];
  }
  int maxi = 0;
  for (int i = -1; i < 2; i++) {
    int nc1 = col1 + i;
    for (int j = -1; j < 2; j++) {
      int nc2 = col2 + j;
      if (nc1 < 0 || nc2 < 0 || nc1 >= m || nc2 >= m)
        continue;
      if (nc1 == nc2) {

        maxi =
            max(maxi, grid[row][col1] + solve(row + 1, nc1, nc2, grid, n, m));
      } else {
        maxi = max(maxi, grid[row][col1] + grid[row][col2] +
                             solve(row + 1, nc1, nc2, grid, n, m));
      }
    }
  }

  return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
  // Write your code here.
  return solve(0,0,c-1,grid,r,c);
}
//TIME COMPLEXITY
//tc=O(3^n * 3^n)

//sc=O(n)

//////////////////////MEMOIZAtion///////////////////
#include <bits/stdc++.h>
int solve(int row, int col1,int col2, vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>>&dp) {
  if (row == n - 1) {

    if (col1 == col2)
      return grid[row][col1];

    return grid[row][col1] + grid[row][col2];
  }
  if(dp[row][col1][col2]!=-1)
  return dp[row][col1][col2];
  int maxi = 0;
  for (int i = -1; i < 2; i++) {
    int nc1 = col1 + i;
    for (int j = -1; j < 2; j++) {
      int nc2 = col2 + j;
      if (nc1 < 0 || nc2 < 0 || nc1 >= m || nc2 >= m)
        continue;
      if (nc1 == nc2) {

        maxi =
            max(maxi, grid[row][col1] + solve(row + 1, nc1, nc2, grid, n, m,dp));
      } else {
        maxi = max(maxi, grid[row][col1] + grid[row][col2] +
                             solve(row + 1, nc1, nc2, grid, n, m,dp));
      }
    }
  }

  return dp[row][col1][col2]=maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
  // Write your code here.
  vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
  return solve(0,0,c-1,grid,r,c,dp);
}
//////TIME COMPLEXITY
//tc=O(N*M*M)*9

//sc=O(N)+O(N*M*M)
///////////////////////Tabulation///////////////////

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum chocolates that can be collected
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Create a 3D DP array to store computed results
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    // Initialize the DP array for the last row
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // Outer nested loops for traversing the DP array from the second-to-last row up to the first row
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;

                // Inner nested loops to try out 9 options (diagonal moves)
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9; // A very large negative value to represent an invalid move
                        else
                            ans += dp[i + 1][j1 + di][j2 + dj]; // Include the DP result from the next row

                        maxi = max(ans, maxi); // Update the maximum result
                    }
                }
                dp[i][j1][j2] = maxi; // Store the maximum result for this state in the DP array
            }
        }
    }

    // The maximum chocolates that can be collected is stored at the top-left corner of the DP array
    return dp[0][0][m - 1];
}

int main() {
    // Define the grid as a 2D vector
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size(); // Number of rows
    int m = matrix[0].size(); // Number of columns

    // Call the maximumChocolates function and print the result
    cout << maximumChocolates(n, m, matrix);

    return 0;
}


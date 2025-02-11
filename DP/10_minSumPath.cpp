/*Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', 
with 'N' rows and 'M' columns. Each point in the grid has some cost associated with it.
Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which
minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.*/

#include <bits/stdc++.h>
using namespace std;
///////////////////////////Recursion///////////////////////////
int solve(int row, int col, vector<vector<int>> &grid)
{
    if (row < 0 || col < 0)
        return 1e9;
    if (row == 0 && col == 0)
        return grid[row][col];

    int up = grid[row][col] + solve(row - 1, col, grid);
    int left = grid[row][col] + solve(row, col - 1, grid);

    return min(up, left);
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    return solve(n - 1, m - 1, grid);
}
////////////////////////////////////Memoization//////////////////////
#include <bits/stdc++.h>
int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row < 0 || col < 0)
        return 1e9;
    if (dp[row][col] != -1)
        return dp[row][col];
    if (row == 0 && col == 0)
        return dp[row][col] = grid[row][col];

    int up = grid[row][col] + solve(row - 1, col, grid, dp);
    int left = grid[row][col] + solve(row, col - 1, grid, dp);

    return dp[row][col] = min(up, left);
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, grid, dp);
}
////////////////////////////////Tabulation//////////////////////
#include <bits/stdc++.h>
int solve(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int up = grid[i][j], left = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[n - 1][m - 1];
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.

    return solve(grid);
}
/////////////////////Space//////////////////////////
#include <bits/stdc++.h>
int solve(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> dp(m, -1);

    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                temp[j] = grid[i][j];
            else
            {
                int up = grid[i][j], left = grid[i][j];
                if (i > 0)
                    up += dp[j];
                else
                    up += 1e9;
                if (j > 0)
                    left += temp[j - 1];
                else
                    left += 1e9;

                temp[j] = min(up, left);
            }
        }
        dp = temp;
    }

    return dp[m - 1];
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.

    return solve(grid);
}

/*You are given a triangular array/list 'TRIANGLE'. 
Your task is to return the minimum path sum to reach from the top to the bottom row.
The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
You can move only to the adjacent number of row below each step. For example, 
if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.
*/
#include <bits/stdc++.h>
using namespace std;
/////////////////////////////simple///////////////////////////////
#include <bits/stdc++.h>
int solve(int i, int j, vector<vector<int>> &triangle, int n)
{

    if (i == n - 1)
        return triangle[i][j];

    if (i >= n || j > i + 1)
        return 0;

    int down = triangle[i][j];
    int diagonal = triangle[i][j];

    down = triangle[i][j] + solve(i + 1, j, triangle, n);
    diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, n);

    return min(down, diagonal);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.

    return solve(0, 0, triangle, n);
}
////////////////////////////memoization/////////////////////////////////
int solve(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == n - 1)
        return dp[i][j] = triangle[i][j];

    if (i >= n || j > i + 1)
        return 0;

    int down = triangle[i][j];
    int diagonal = triangle[i][j];

    down = triangle[i][j] + solve(i + 1, j, triangle, n, dp);
    diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, diagonal);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, 0, triangle, n, dp);
}
///////////////////////////////Tabulation/////////////////////////
#include <bits/stdc++.h>
int solve(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }
    int down = 0, diagonal = 0, curr = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            down = triangle[i][j] + dp[i + 1][j];
            diagonal = triangle[i][j] + dp[i + 1][j + 1];
            curr = min(down, diagonal);
            dp[i][j] = curr;
        }
    }

    return dp[0][0];
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.

    return solve(triangle, n);
}
//////////////////////////////////Space////////////////////////////////////
#include <bits/stdc++.h>

int solve(vector<vector<int>> &triangle, int n)
{
    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++)
    {
        dp[i] = triangle[n - 1][i];
    }

    int down = 0, diagonal = 0, curr = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> temp(n, 0);
        for (int j = i; j >= 0; j--)
        {
            down = triangle[i][j] + dp[j];
            diagonal = triangle[i][j] + dp[j + 1];
            curr = min(down, diagonal);
            temp[j] = curr;
        }
        dp = temp;
    }
    return dp[0];
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.

    return solve(triangle, n);
}
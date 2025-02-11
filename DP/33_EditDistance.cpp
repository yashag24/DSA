#include <bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
////////////////////Simple/////////////////////
class Solution
{
public:
    int solve(string &s, string &t, int i, int j)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (s[i] == t[j])
            return solve(s, t, i - 1, j - 1);

        return 1 + min({solve(s, t, i, j - 1), solve(s, t, i - 1, j), solve(s, t, i - 1, j - 1)});
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        return solve(word1, word2, n - 1, m - 1);
    }
};
////////////////////////////Memoization/////////////////////
class Solution
{
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = solve(s, t, i - 1, j - 1, dp);

        return dp[i][j] = 1 + min({solve(s, t, i, j - 1, dp), solve(s, t, i - 1, j, dp), solve(s, t, i - 1, j - 1, dp)});
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(word1, word2, n - 1, m - 1, dp);
    }
};
///////////////////////////////Tabulation///////////////
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {

                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }

        return dp[n][m];
    }
};
////////////////////////Space//////////////////////////////

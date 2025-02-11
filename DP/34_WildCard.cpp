#include <bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
//////////////////////////////////Recur////////////////
class Solution
{
public:
    bool solve(string s, string p, int i, int j)
    {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;

        if (i >= 0 && j < 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (s[k] != '*')
                    return false;
            }
            return true;
        }

        if (s[i] == p[j] || s[i] == '?')
            return solve(s, p, i - 1, j - 1);
        if (s[i] == '*')
            return solve(s, p, i, j - 1) || solve(s, p, i - 1, j);
        return false;
    }
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        return solve(p, s, m - 1, n - 1);
    }
};
//////////////////////////MEmoize/////////////////////////
class Solution
{
public:
    bool solve(string &p, string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return true; // Both strings are fully matched
        if (i < 0)
            return false; // Pattern exhausted but string still remains
        if (j < 0)
        {
            // If string is exhausted, ensure remaining pattern is all '*'
            for (int k = 0; k <= i; k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (p[i] == s[j] || p[i] == '?')
            return dp[i][j] = solve(p, s, i - 1, j - 1, dp);
        if (p[i] == '*')
            return dp[i][j] = solve(p, s, i - 1, j, dp) || solve(p, s, i, j - 1, dp);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(p, s, m - 1, n - 1, dp);
    }
};

////////////////Tabulize
class Solution {
public:

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;

        // Initialize the dp array for patterns starting with '*'
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            } else {
                dp[0][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[n][m];
    }
};

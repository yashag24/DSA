#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        // Step 1: Build the DP table
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // Step 2: Use a memoized map to store intermediate results
        map<pair<int, int>, set<string>> memo;
        set<string> res = findAllLCS(n, m, s, t, dp, memo);
        
        return vector<string>(res.begin(), res.end());
    }


    set<string> findAllLCS(int i, int j, string &s, string &t, vector<vector<int>> &dp, map<pair<int, int>, set<string>> &memo) {
        // If already computed for this (i, j), return the result
        if(memo.find({i, j}) != memo.end()) {
            return memo[{i, j}];
        }
        
        set<string> res;
        
        // Base case: if we've reached the beginning of either string
        if(i == 0 || j == 0) {
            res.insert("");
            return res;
        }
        
        if(s[i-1] == t[j-1]) {
            set<string> temp = findAllLCS(i-1, j-1, s, t, dp, memo);
            for(auto str : temp) {
                res.insert(str + s[i-1]);
            }
        } else {
            if(dp[i-1][j] >= dp[i][j-1]) {
                res = findAllLCS(i-1, j, s, t, dp, memo);
            }
            if(dp[i-1][j] <= dp[i][j-1]) {
                set<string> temp = findAllLCS(i, j-1, s, t, dp, memo);
                res.insert(temp.begin(), temp.end());
            }
        }
        
        // Memoize the result for this (i, j)
        memo[{i, j}] = res;
        return res;
    }
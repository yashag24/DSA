#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
#include <bits/stdc++.h> 
using namespace std;

string shortestSupersequence(string a, string b) {
    int n = a.length();
    int m = b.length();
    
    // Step 1: Calculate LCS using Dynamic Programming
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    // Step 2: Construct the Shortest Common Supersequence using the LCS table
    int i = n, j = m;
    string result = "";
    
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            result.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            result.push_back(a[i - 1]);
            i--;
        } else {
            result.push_back(b[j - 1]);
            j--;
        }
    }
    
    // Add remaining characters of a or b
    while (i > 0) {
        result.push_back(a[i - 1]);
        i--;
    }
    while (j > 0) {
        result.push_back(b[j - 1]);
        j--;
    }
    
    // Reverse the result because we built it backwards
    reverse(result.begin(), result.end());
    
    return result;
}
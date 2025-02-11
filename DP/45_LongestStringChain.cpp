#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}



class Solution {
public:
    bool compare(string a, string prev) {
        int n = a.size();
        int m = prev.size();

        if (n != m + 1)
            return false;

        int i = 0, j = 0;
        while (i < n) {
            if (a[i] == prev[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j == m && i == n;
    }
    static bool cmp(string a, string b) { return a.size() < b.size(); }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {
                if (compare(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
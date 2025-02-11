#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), indexes(n);
        int maxi = -1, maxin = -1;
        for (int i = 0; i < n; i++) {
            indexes[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    indexes[i] = prev;
                }
            }
            if (maxi < dp[i]) {
                maxi = dp[i];
                maxin = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[maxin]);
        while (indexes[maxin] != maxin) {
            maxin = indexes[maxin];
            ans.push_back(nums[maxin]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
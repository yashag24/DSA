//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        // Code here
                
        vector<int> dp(n, 1),indexes(n);
        int maxi = -1, maxin = -1;
        for (int i = 0; i < n; i++) 
        {   indexes[i]=i;
            for (int prev = 0; prev < i; prev++) 
            {
                if (nums[i] > nums[prev] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    indexes[i]=prev;    
                }
            }
            if (maxi < dp[i]) 
            {
                maxi = dp[i];
                maxin = i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[maxin]);
        while(indexes[maxin]!=maxin)
        {
            maxin = indexes[maxin];
            ans.push_back(nums[maxin]);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
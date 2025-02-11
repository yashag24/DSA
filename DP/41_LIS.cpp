#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}

////////////////Recur///////////////
class Solution {
public:

    int solve(vector<int>&nums,int n ,int i , int last)
    {
        if(i==n)
            return 0;
        
        int plen = 0;
        int len = 0;

        len = solve(nums,n,i+1,last);
        if(last == -1)
            plen = 1 + solve(nums,n,i+1,i);
        else if(nums[last]<nums[i])
            plen = 1 + solve(nums,n,i+1,i);


        return max(len,plen);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,n,0,-1);
    }
};
//////////////////////Memoize/////////////////
class Solution {
public:
    int solve(vector<int>& nums, int n, int i, int last,
              vector<vector<int>>& dp) {
        if (i == n)
            return 0;

        if (dp[i][last + 1] != -1)
            return dp[i][last + 1];
        int plen = 0;
        int len = 0;
        len = solve(nums, n, i + 1, last, dp);

        if (last == -1 || nums[last] < nums[i])
            plen = 1 + solve(nums, n, i + 1, i, dp);

        return dp[i][last + 1] = max(len, plen);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(nums, n, 0, -1, dp);
    }
};
///////////////////////////Tabbulize///////////
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

       
        for (int i = n - 1; i >= 0; i--) {
            for (int last = i - 1; last >= -1; last--) {
                
                int len = dp[i + 1][last + 1];
                int plen = 0;
                if (last == -1 || nums[last] < nums[i])
                    plen =  1 + dp[i + 1][i + 1];

                
                dp[i][last + 1] = max(len,plen);
            }
        }

        return dp[0][0];
    }
};
//////////////////////Space.///////
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n + 1, 0);
        vector<int>curr(n + 1, 0);

       
        for (int i = n - 1; i >= 0; i--) {
            for (int last = i - 1; last >= -1; last--) {
                
                int len = dp[last + 1];
                int plen = 0;
                if (last == -1 || nums[last] < nums[i])
                    plen =  1 + dp[i + 1];

                
                curr[last + 1] = max(len,plen);
            }
            dp=curr;
        }

        return dp[-1+1];
    }
};
/////////////////MEthod 2 /////////////////
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        for(int i =0;i<n;i++)
        {
            for(int prev =0;prev<i;prev++)
            {
                if(nums[i]>nums[prev])
                    dp[i]=max(1+dp[prev],dp[i]);
            }
        }

        int maxi =-1;
        for(int i =0;i<n;i++)
            maxi=max(maxi,dp[i]);

        return maxi;
    }
};
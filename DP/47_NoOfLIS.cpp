#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {

        int n = nums.size();
        int maxi = 0;
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
     
        for(int i=0;i<n;i++)
        {
            for(int prev = 0 ;prev<i;prev++)
            {

                if(nums[prev]<nums[i])
                {
                    if(1+dp[prev]>dp[i])
                    {
                        dp[i]=dp[prev]+1;
                        cnt[i]=cnt[prev];
                    }
                    else if(1+dp[prev]==dp[i])
                    {
                        cnt[i]+=cnt[prev];
                    }

                }
            }
                if(maxi<dp[i])
                {
                    maxi=dp[i];
                    
                }
        }

        int ans =0;
        for(int i =0;i<n;i++)
        {
            if(dp[i]==maxi)
            {
                ans+=cnt[i];
            }
        }
        return ans;
    }
};
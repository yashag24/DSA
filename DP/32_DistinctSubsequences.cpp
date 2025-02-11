#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
///////////////////////Recur//////////////////
class Solution {
public:
    int solve(string &s,string &t,int i,int j)
    {
        if(j<0)
            return 1;
        if(i<0 )
            return 0;
        if(s[i]==t[j])
            return solve(s,t,i-1,j-1) + solve(s,t,i-1,j);
        else 
        return solve(s,t,i-1,j);
    }
    int numDistinct(string s, string t) {
        int n  = s.size();
        int m  = t.size();
        
        return solve(s,t,n-1,m-1);
    }
};
///////////////////////Memoization//////////////

class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp)
    {
        if(j<0)
            return 1;
        if(i<0 )
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]=solve(s,t,i-1,j-1,dp) + solve(s,t,i-1,j,dp);
        else 
        return dp[i][j]=solve(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        int n  = s.size();
        int m  = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,t,n-1,m-1,dp);
    }
};

/////////////////////////////Tabulation////////////////////////

class Solution {
public:
    int prime = 1e9+7;
    
    int numDistinct(string s, string t) {
        int n  = s.size();
        int m  = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i =0;i<=n;i++)
        {
            dp[i][0]=1;
        }

        for(int i =1;i<=n;i++){
            for(int j =1 ;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%prime;
                else dp[i][j]=dp[i-1][j];

            }
        }
        
        return dp[n][m];
    }
};
//////////////////////////////Space////////////////////////////
class Solution {
public:
    int mod = 1e9+7;
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<int>dp(m+1,0);
        
        dp[0]=1;

        for(int i =1;i<n+1;i++)
        {
            vector<int>curr(m+1,0);
            curr[0]=1;
            for(int j =1;j<m+1;j++)
            {
                if(s[i-1]==t[j-1])
                    curr[j]=(dp[j-1]+dp[j])%mod;
                else curr[j]=dp[j]%mod;
            }
            dp=curr;
        }
        return dp[m];
    }
};

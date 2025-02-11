#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
int longestPalindromic(string &s,string &t,int is,int it,vector<vector<int>>&dp){
	if(is<0 || it<0)
		return 0;
	if(dp[is][it]!=-1)
		return dp[is][it];
	if(s[is]==t[it])
		return dp[is][it]=1+longestPalindromic(s,  t, is-1, it-1,dp);
	return dp[is][it]=max(longestPalindromic(s, t, is-1, it,dp),longestPalindromic(s, t, is, it-1,dp));	

}

int canYouMake(string &s1, string &s2){
    // Write your code here.
    
	int n = s1.length();
	int m = s2.length();
	
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	int ans = longestPalindromic(s1, s2, n-1, m-1,dp);

    return m+n-(2*ans);
}
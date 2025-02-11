#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
int longestPalindromic(string &t,string &s,int is,int it,vector<vector<int>>&dp){
	if(is<0 || it<0)
		return 0;
	if(dp[is][it]!=-1)
		return dp[is][it];
	if(s[is]==t[it])
		return dp[is][it]=1+longestPalindromic(t,  s, is-1, it-1,dp);
	return dp[is][it]=max(longestPalindromic(t, s, is-1, it,dp),longestPalindromic(t, s, is, it-1,dp));	

}


int minimumInsertions(string &str)
{
	string t =str;
	int n = str.length();
	reverse(t.begin(),t.end());
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	int ans = longestPalindromic(t, str, n-1, n-1,dp);
	// Write your code here.
	return n-ans;
}

#include<bits/stdc++.h>
using namespace std;
///////////////simple////////////////////////
int solve(int n,int i,int m,int j ,string s,string t  ){
	if(i>=n || j>=m )
	return 0;
	if(s[i]==t[j])
	{
	 return 1 + solve(n,i+1,m,j+1,s,t);

	}
	return  max(solve(n,i+1,m,j,s,t),solve(n,i,m,j+1,s,t));

}


int lcs(string s, string t)
{
	int n=t.size();
	int m=s.size();
	int i =0,j=0;
	
	return solve(m,i,n,j,s,t);
	//Write your code here
}
//////////////////////////memoization////////////////////////
#include <bits/stdc++.h>
int solve(int n, int i, int m, int j, string s, string t,
          vector<vector<int>> &dp) {
  if (i >= n || j >= m)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  if (s[i] == t[j]) {
    return dp[i][j] = 1 + solve(n, i + 1, m, j + 1, s, t, dp);
  }
  return dp[i][j] = max(solve(n, i + 1, m, j, s, t, dp),
                        solve(n, i, m, j + 1, s, t, dp));
}

int lcs(string s, string t) {
  int n = t.size();
  int m = s.size();
  int i = 0, j = 0;
  vector<vector<int>> dp(m, vector<int>(n, -1));
  return solve(m, i, n, j, s, t, dp);
  // Write your code here
}
////////////////////////////Tabulation///////////
int lcs(string s, string t) {
  int n = t.size();
  int m = s.size();
  int i = 0, j = 0;
  vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
  for(int i =1;i<=m;i++){
    for(int j =1;j<=n;j++){
        if(s[i-1]==t[j-1])
        dp[i][j]=1+dp[i-1][j-1];
        else
        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
  }
  return dp[m][n];
  // Write your code here
}
//////////////////////Space//////////
int lcs(string s, string t) {
    int m = s.size();
    int n = t.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        vector<int> curr(n + 1, 0); 
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + dp[j - 1];
            else
                curr[j] = max(curr[j - 1], dp[j]);
        }
        dp = curr;
    }

    return dp[n];
}
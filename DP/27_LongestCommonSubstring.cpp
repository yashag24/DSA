#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
////////////////Tabulation//////////////////
int lcs(string &s, string &t){
    // Write your code here.
      int n = t.size();
  int m = s.size();
  int i = 0, j = 0;
  int ans=0;
  vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
  for(int i =1;i<=m;i++){
    for(int j =1;j<=n;j++){
        if(s[i-1]==t[j-1]){
        dp[i][j]=1+dp[i-1][j-1];
        ans=max(ans,dp[i][j]);
        }
        else
        dp[i][j]=0;
    }
  }
  return ans;

}
////////////Space;/////////////
int lcs(string &s, string &t){
    // Write your code here.
      int n = t.size();
  int m = s.size();

  int ans=0;
 vector<int> dp(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        vector<int> curr(n + 1, 0); 
        for (int j = 1; j <= n; j++) {
          if (s[i - 1] == t[j - 1]) {
            curr[j] = 1 + dp[j - 1];
            ans=max(ans,curr[j]);
          } else
            curr[j] =0;
        }
        dp = curr;
    }

    return ans;

}
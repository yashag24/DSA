#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.

	int tsum = accumulate(arr.begin(),arr.end(),0);

	vector<vector<bool>>dp(n,vector<bool>(tsum+1,0));

	for(int i = 0;i<n;i++ ){
		dp[i][0]=1;
	}
	if(arr[0]<=tsum)
	dp[0][arr[0]]=1;

	for(int i =1;i<n;i++){
		for(int k =0;k<=tsum;k++){
			bool ntake = dp[i-1][k];
			bool take = false;
			if(k>=arr[i])
				take = dp[i-1][k-arr[i]];

			dp[i][k]=ntake | take;
		}
	}
	int mini = INT_MAX;
	for(int i = 0 ;i<=tsum;i++){
		if(dp[n-1][i])
		{
			int s2 = tsum-i;
			mini = min (mini,abs(s2-i));



		}


	}

return mini;
}

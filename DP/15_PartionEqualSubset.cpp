#include<bits/stdc++.h>
using namespace std;
////////////////////REcur/////////////
#include<bits/stdc++.h>
bool solve(vector<int>&arr,int n , int tar,int i){
	if(i==0)
	return tar==arr[0];

	if(tar==0)
	return 1;

	bool npick=solve(arr,n,tar,i-1);


	bool pick=0;
	if(tar>=arr[i])
	pick=solve(arr,n,tar-arr[i],i-1);
	return pick | npick;
}



bool canPartition(vector<int> &arr, int n)
{

	int sum = std::accumulate(arr.begin(), arr.end(), 0);
	if(sum&1)
	return 0;

	return solve(arr,n,sum/2,n-1);
	// Write your code here.
}

/////////////////////////////Memoization////////////////////////////////
bool solve(vector<int>&arr,int n , int tar,int i,vector<vector<int>>&dp ){
	if(i==0)
	return tar==arr[0];

	if(tar==0)
	return 1;
	if(dp[i][tar]!=-1)
	return dp[i][tar];
	bool npick=solve(arr,n,tar,i-1,dp);


	bool pick=0;
	if(tar>=arr[i])
	pick=solve(arr,n,tar-arr[i],i-1,dp);
	return dp[i][tar]=pick | npick;
}



bool canPartition(vector<int> &arr, int n)
{

	int sum = std::accumulate(arr.begin(), arr.end(), 0);
	if(sum&1)
	return 0;
	
    vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
	return solve(arr,n,sum/2,n-1,dp);
	
}
/////////////////////////////Tabulation////////////////////////////////

bool canPartition(vector<int> &arr, int n)
{

	int sum = std::accumulate(arr.begin(), arr.end(), 0);
	if(sum&1)
	return 0;
	
    vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
	
    for(int i =0;i<n;i++)
        dp[i][0]=1;
        if(arr[0]<=sum/2)
    dp[0][arr[0]]=1;
    for(int i =1;i<n;i++){
        for(int k =0;k<=sum/2;k++){
	        bool npick=dp[i-1][k];
            bool pick=0;
	        if(k>=arr[i])
	        pick=dp[i-1][k-arr[i]];

            dp[i][k]=pick | npick;


        }
    }
	return dp[n-1][sum/2];
}
/////////////////////////////Space////////////////////////////////
bool canPartition(vector<int> &arr, int n)
{

	int sum = std::accumulate(arr.begin(), arr.end(), 0);
	if(sum&1)
	return 0;
	
    vector<bool>dp((sum/2)+1,0);
    
	dp[0]=1;
    
	if(arr[0]<=sum/2)
    dp[arr[0]]=1;

    for(int i =1;i<n;i++){
    vector<bool>curr((sum/2)+1,0);
	curr[0]=1;
        for(int k =0;k<=sum/2;k++){
	        bool npick=dp[k];
            bool pick=0;
	        if(k>=arr[i])
	        pick=dp[k-arr[i]];

            curr[k]=pick | npick;

        }
        dp=curr;
    }
	return dp[sum/2];
}
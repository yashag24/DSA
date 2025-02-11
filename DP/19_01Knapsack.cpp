#include<bits/stdc++.h>
using namespace std;
//////////////////////////////simple/////////////////////////////
int solve(vector<int> weight, vector<int> value, int n, int W,int i){
	if(i==0){
		if(weight[i]<=W){
			return value[i];
		}
		return 0;
	}
	

	int pick =0, notpick=0;
	notpick=solve(weight,value,n,W,i-1);
	if(W>=weight[i]){
	pick=value[i]+solve(weight,value,n,W-weight[i],i-1);
	}

	
return max(pick,notpick);
} 
int knapsack(vector<int> weight, vector<int> value, int n, int maxweight) 
{	
	// Write your code here
	return solve(weight,value,n,maxweight,n-1);
}
////////////////////////////memoization/////////////////////////
#include <bits/stdc++.h>
int solve(vector<int> weight, vector<int> value, int n, int W,int i,vector<vector<int>>&dp){
	if(i==0){
		if(weight[i]<=W){
			return value[i];
		}
		return 0;
	}
	if(dp[i][W]!=-1)
	return dp[i][W];

	int pick =0, notpick=0;
	notpick=solve(weight,value,n,W,i-1,dp);
	if(W>=weight[i]){
	pick=value[i]+solve(weight,value,n,W-weight[i],i-1,dp);
	}

	
return dp[i][W]= max(pick,notpick);
} 
int knapsack(vector<int> weight, vector<int> value, int n, int maxweight) 
{	vector<vector<int>>dp(n,vector<int>(maxweight+1,-1));
	// Write your code here
	return solve(weight,value,n,maxweight,n-1,dp);
}

///////////////////////////////////////Tabulation//////////////////////

#include <bits/stdc++.h>
using namespace std;

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    // Create a 2D DP table with dimensions n x W+1 and initialize it with zeros
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base condition: Fill in the first row for the weight of the first item
    for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = val[0];
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            // Calculate the maximum value by either excluding the current item or including it
            int notTaken = dp[ind - 1][cap];
            int taken = INT_MIN;

            // Check if the current item can be included without exceeding the knapsack's capacity
            if (wt[ind] <= cap) {
                taken = val[ind] + dp[ind - 1][cap - wt[ind]];
            }

            // Update the DP table
            dp[ind][cap] = max(notTaken, taken);
        }
    }

    // The final result is in the last cell of the DP table
    return dp[n - 1][W];
}




////////////////Space/////////////
int knapsack(vector<int> &wt, vector<int> &val, int n, int W) {
  vector<int>dp(W+1,0);
    for (int i = wt[0]; i <= W; i++) {
        dp[i] = val[0];
    }
    for(int i =1;i<n;i++){
  vector<int>curr(W+1,0);
        for(int j =0;j<=W;j++){
            int npick = dp[j];
            int pick = INT_MIN;
            if(j>=wt[i])
                pick = val[i]+ dp[j-wt[i]];
            
            curr[j]=max(npick,pick);
        }
        dp=curr;
    }


    return dp[W];
}

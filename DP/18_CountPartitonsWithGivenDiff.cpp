#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
int mod =(int)1e9+7;

int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    return dp[n-1][tar];
}

int countPartitions(int n, int d, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d <0 || (totSum-d)%2 ) return 0;
    
    return findWays(arr,(totSum-d)/2);
}
///////////////tabulatiomn

int targetSum(int n, int target, vector<int>& arr) {
    int tsum = accumulate(arr.begin(), arr.end(), 0);
    
    if ((tsum - target) < 0 || (tsum - target) % 2 != 0)
        return 0;
    
    int newTarget = (tsum - target) / 2;
    vector<vector<int>> dp(n, vector<int>(newTarget + 1, 0));
    if(arr[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1; 
if(arr[0]!=0 && arr[0]<=newTarget) dp[0][arr[0]] = 1;
    for(int i =0;i<n;i++){
        dp[i][0]=1;
    }

    for(int i =1;i<n;i++){
        for(int k =0;k<=newTarget;k++){
            int npick = dp[i-1][k];
            int pick =0;

            if(arr[i]<=k)
            pick = dp[i-1][k-arr[i]];
            dp[i][k]=pick+npick;
        }
    }
    return dp[n-1][newTarget];
}
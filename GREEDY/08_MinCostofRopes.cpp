//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
    priority_queue<long long int,vector<long long int>,greater<long long int>>pq;
    if(n==1)
    return 0;
    for(int i = 0;i<n;i++)
    pq.push(arr[i]);
    
   long long int sum=0,cost=0;
   long long int a=0,b=0;
    
    while(!pq.empty()){
        a=pq.top();
        pq.pop();
        if(pq.empty())
        return cost+a;
        b=pq.top();
        pq.pop();
        
        sum = a+b;
        cost+=sum;
        if(pq.empty())
        return cost;
        else{
            pq.push(sum);
        }
    }
    return cost;
    
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
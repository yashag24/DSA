//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        int sunday =S/7;
        
        int buyday=S-sunday;
    int totalreq= M*S;
    int ans;
    if(totalreq%N==0)
    ans= totalreq/N;
    else
    ans= totalreq/N  +1;
    
    if(ans<=buyday)
    return ans;
    else 
    return -1;
    
    
    }
};
// 48 28 27

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends
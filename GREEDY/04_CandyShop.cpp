//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int>candy(N);
        for(int i  =0 ;i<N;i++){
            candy[i]=candies[i];        
            
        }

        sort(candy.begin(),candy.end());
        
        int i = 0,j=N-1;
        int minMoney=0;
        while(i<=j){
            minMoney+=candy[i];
            i++;
            j-=K;
            
            
        }
            //  k=K;
        
        j  = 0, i=N-1;
        int maxMoney=0;
        while(i>=j){
            maxMoney+=candy[i];
          
        j+=K;
            i--;
            
        }
        return {minMoney,maxMoney};
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
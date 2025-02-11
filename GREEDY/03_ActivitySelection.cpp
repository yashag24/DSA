//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        
        int cnt =1;
        vector<pair<int,int>>sch;
        for(int i =0;i<n;i++)
            sch.push_back({end[i],start[i]});
        
        sort(sch.begin(),sch.end());
        int latest = sch[0].first ;
        
        for(int i = 1;i<n;i++)
            if(sch[i].second>latest)
            {
                latest=sch[i].first;
                cnt++;
            }
        
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>>adj[n+1];
        
        for(int i =0;i<m;i++){
        
            int u =edges[i][0];
            int v =edges[i][1];
            int wt =edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        
        }
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dis(n+1 , INT_MAX);
        vector<int>parent(n+1);
        for(int i =1;i<n+1;i++)
        parent[i]=i;
        
        dis[1]=0;
        pq.push({0,1});//dis,node
        
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            int node=front.second;
            int dist=front.first;
            
            for (auto it:adj[node]){
                int neigh=it.first;
                int wt=it.second;
                
                if(dis[neigh]>dist+wt){
                    dis[neigh]=dist+wt;
                    parent[neigh]=node;
                    pq.push({dis[neigh],neigh});
                }
            }
            
            
            
        }
    if(dis[n]==INT_MAX)
    return {-1};
    int dest=n;    
    int node = dest;
    vector<int>arr;
    arr.push_back(n);
    while(parent[node]!=node){
        arr.push_back(parent[node]);
        node=parent[node];
    }
    arr.push_back(1);
    reverse(arr.begin(),arr.end());
    return arr;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int,int>,int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0],edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1],edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans=0;
        for(int i=2;i<res.size();i++)
        {
            ans+=mp[{res[i],res[i-1]}];
        }
        if(res.size()==1) ans=res[0];
        cout<<ans<<endl;
    }
}

// } Driver Code Ends
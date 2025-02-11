//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
int timer=0;
class Solution {
    void dfs(int node,int parent,vector<int>adj[],vector<bool>&vis,vector<int>&time,vector<int>&low,vector<bool>&ap){

        vis[node]=1;
        time[node]=low[node]=timer++;
        int child=0;
        for(auto it:adj[node]){
           if(it==parent)continue;
           if(!vis[it]){
               child++;
               dfs(it,node,adj,vis,time,low,ap);
                low[node]=min(low[node],low[it]);
                
                if(low[it]>=time[node] && parent!= -1){
                    ap[node]=1;
                }
               
           }
           else{
               low[node]=min(time[it],low[node]);
           }
            
            
        }
        if(child>1 && parent == -1){
            ap[node]=1;
        }
    }
    
    
    
    
  public:
  
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<bool>vis(n,0);
        vector<int>time(n);
        vector<int>low(n);
        vector<bool>ap(n,0);
        
        dfs(0,-1,adj,vis,time,low,ap);
        vector<int>ans;
        for(int i =0;i<n;i++){
            if(ap[i]==1)
            ans.push_back(i);
        }
        
        if( ans.size() == 0 )
        return {-1} ;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
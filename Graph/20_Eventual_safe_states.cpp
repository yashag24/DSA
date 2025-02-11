//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    bool checkbydfs(int src,vector<int>adj[],vector<bool>&vis,vector<bool>&pathvis)
    {
        pathvis[src]=1;
        vis[src]=1;
        
        for(auto it:adj[src])
        {   if(!vis[it])
            {
                if(checkbydfs(it,adj,vis,pathvis)==true){
                    return true;
                }
                            
            }
            else if(pathvis[it]==1){
                return true;
            }
        
        
            
        }
        
        pathvis[src]=0;
        return false;
    }
        
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        vector<bool>vis(V,0);
        vector<bool>pathvis(V,0);
        vector<int>ans;
        bool flag;
        for(int i=0;i<V;i++)
        {   flag=false;
            
                
            if(checkbydfs(i,adj,vis,pathvis)==true)
            {
                flag=true;
            }    

             if(flag==false)
             {
                ans.push_back(i);   
             }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
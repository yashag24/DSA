//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void getdfs(vector<int> adj[], int vis[], vector<int> &dfs, int node)
    {
        if (vis[node] == 1)
            return;
        vis[node] = 1;
        dfs.push_back(node);

        for (int i = 0; i < adj[node].size(); i++)
        {

            getdfs(adj, vis, dfs, adj[node][i]);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        vector<int> dfs;
        getdfs(adj, vis, dfs, 0);
        return dfs;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool detectloop(vector<int> adj[], int vis[], int src)
    {
        queue<pair<int, int>> q;
        q.push({src, -1});
        vis[src] = 1;

        while (!q.empty())
        {
            int parent = q.front().second;
            int node = q.front().first;
            q.pop();
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (parent != it)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detectloop(adj, vis, i) == true)
                {
                    return true;
                }
            }
        }

        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    void getTopodfs(vector<pair<int, int>> adj[], vector<bool> &vis, int src, stack<int> &st)
    {
        vis[src] = 1;

        for (auto it : adj[src])
        {
            int neigh = it.first;
            if (!vis[neigh])
            {
                getTopodfs(adj, vis, neigh, st);
            }
        }

        st.push(src);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int dis = edges[i][2];
            adj[u].push_back({v, dis});
        }
        vector<bool> vis(N, 0);

        stack<int> st;
        for (int i = 0; i < N; i++)
        {

            if (vis[i] == 0)
            {
                // getting topo sort through dfs
                getTopodfs(adj, vis, i, st);
            }
        }
        // vector<int>ans(N,-1);
        vector<int> dis(N, 1e9);
        dis[0] = 0; // bcz we have to 0 as starting node here

        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto it : adj[node])
            {
                int neigh = it.first;
                int wt = it.second;
                dis[neigh] = min(dis[neigh], dis[node] + wt);
            }
        }

        for (int i = 0; i < dis.size(); i++)
        {
            if (dis[i] == 1e9)
                dis[i] = -1;
        }

        return dis;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
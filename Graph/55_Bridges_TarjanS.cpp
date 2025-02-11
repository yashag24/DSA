#include<bits/stdc++.h>
using namespace std;

int timer = 1;
class Solution {
    void dfs(vector<int> adj[], int parent, int node, vector<bool>& vis,
             vector<int>& time, vector<int>& low,
             vector<vector<int>>& bridges) {

        vis[node] = 1;
        time[node] = low[node] = timer++;
        for (auto it : adj[node]) {
            if (it == parent)
                continue;
            if (!vis[it]) {
                dfs(adj, node, it, vis, time, low, bridges);
                low[node] = min(low[it], low[node]);
                // checking whether bridge or not
                if (low[it] > time[node])
                    bridges.push_back({node, it});
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<bool> vis(n, 0);
        vector<int> time(n);
        vector<int> low(n);
        vector<int> adj[n];

        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>> bridges;
        dfs(adj, -1, 0, vis, time, low, bridges);
        return bridges;
    }
};
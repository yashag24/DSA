#include <iostream>
#include <vector>
using namespace std;
int main()
{ // n=node m=edges
    // 1 based indexing
    // matrix
    int u, v, m, n;
    cin >> n >> m;
    int adj[n + 1][n + 1];
    for (int i = 1; i < m; i++)
    {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // List
    cin >> n >> m;
    vector<int> ad[n + 1]; 
    for (int i = 1; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
}

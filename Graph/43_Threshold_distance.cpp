//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution { 
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) 
    {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            mat[u][v] = wt;
            mat[v][u] = wt; // Since it's an undirected graph
        }
        
        for (int i = 0; i < n; i++)
            mat[i][i] = 0;

        // Floyd Warshall Algorithm for finding shortest paths
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }

        vector<int> arr(n);
        int mincount = INT_MAX;
        int index = -1;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] <= distanceThreshold)
                    count++;
            }
            if (count <= mincount) {
                mincount = count;
                index = i;
            }
            arr[i] = count;
        }

        return index;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends
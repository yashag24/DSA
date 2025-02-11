//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    void dfs(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &vis,
             vector<pair<int, int>> &vec, int row0, int col0)
    {
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, -1, 0, 1};
        int n = grid.size();
        int m = grid[0].size();
        vec.push_back({row - row0, col - col0});
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nr = row + delr[i];
            int nc = col + delc[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
            {
                dfs(grid, nr, nc, vis, vec, row0, col0);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> s;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    vector<pair<int, int>> vec;
                    dfs(grid, i, j, vis, vec, i, j);
                    s.insert(vec);
                }
            }
        }

        return s.size();
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
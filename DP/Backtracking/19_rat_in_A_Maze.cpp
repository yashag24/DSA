#include <bits/stdc++.h>
using namespace std;
/*
void solve(int r, int c, vector<vector<bool>> &vis, vector<vector<int>> &maze, int n, string s, vector<string> &ans)
{
    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(s);
        return;
    }

    /// down
    if (r < n - 1 && vis[r + 1][c] == 0 && maze[r + 1][c] == 1)
    {
        vis[r][c] = 1;
        solve(r + 1, c, vis, maze, n, s + 'D', ans);
        vis[r][c] = 0;
    }
    /// left
    if (c > 0 && vis[r][c - 1] == 0 && maze[r][c - 1] == 1)
    {
        vis[r][c] = 1;
        solve(r, c - 1, vis, maze, n, s + 'L', ans);
        vis[r][c] = 0;
    }
    /// right
    if (c < n - 1 && vis[r][c + 1] == 0 && maze[r][c + 1] == 1)
    {
        vis[r][c] = 1;
        solve(r, c + 1, vis, maze, n, s + 'R', ans);
        vis[r][c] = 0;
    }
    /// UP
    if (r > 0 && vis[r - 1][c] == 0 && maze[r - 1][c] == 1)
    {
        vis[r][c] = 1;
        solve(r - 1, c, vis, maze, n, s + 'U', ans);
        vis[r][c] = 0;
    }
}
vector<string> RatMAze(vector<vector<int>> &maze, int n)
{
    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    vector<string> ans;
    solve(0, 0, vis, maze, n, "", ans);
    return ans;
}
*/
///////////////METHOD 2///////////////////
void solve(int r, int c, vector<vector<bool>> &vis, vector<vector<int>> &maze, int n, string s, vector<string> &ans, vector<pair<int, int>> &dir, vector<char> &dirc)
{
    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(s);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] && maze[nr][nc])
        {
            vis[r][c] = 1;
            solve(nr, nc, vis, maze, n, s + dirc[i], ans, dir, dirc);
            vis[r][c] = 0;
        }
    }
}

vector<string> RatMAze(vector<vector<int>> &maze, int n)
{
    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    vector<string> ans;
    vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    vector<char> dirc = {'D', 'L', 'R', 'U'};
    solve(0, 0, vis, maze, n, "", ans, dir, dirc);
    return ans;
}
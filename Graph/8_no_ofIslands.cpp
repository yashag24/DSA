//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void bfs(vector<vector<int>>&vis,int row,int col,vector<vector<char>>& grid){
    //   if(vis[row][col]==1)
    //       return;
          
          queue<pair<int,int>>q;
          q.push(make_pair(row,col));
          vis[row][col]=1;
            int n=grid.size();
            int m=grid[0].size();
            
          while(!q.empty()){
              auto node=q.front();
              int r=node.first;
              int c=node.second;
              q.pop();
              for(int i=-1;i<=1;i++){
                  for(int j=-1;j<=1;j++){
                      int nr=r+i;
                      int nc=c+j;
                      if(nr>=0 && nc>=0 && nr<n && nc<m ){
                          if(grid[nr][nc]== '1' && !vis[nr][nc]){
                          vis[nr][nc]=1;
                          q.push({nr,nc});}
                      }
                      
                  }
              }
              
          }
      
      
      
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

    //   for(int i=0;i<n;i++){
    //       for(int j=0;j<m;j++){
    //           vis[i][j]=0;
    //       }
    //   }
        
        int count=0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(vis,i,j,grid);
                }
            }
        }
        
      return count;   
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
/////optimized code


class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row,
             int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        int rows = grid.size();
        int columns = grid[0].size();
        static const vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();

            for (const auto& dir : directions) {
                int newRow = curRow + dir.first;
                int newCol = curCol + dir.second;

                if (newRow >= 0 && newCol >= 0 && newRow < rows &&
                    newCol < columns && grid[newRow][newCol] == '1' &&
                    !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(columns, 0));
        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    bfs(grid, vis, i, j);
                }
            }
        }

        return count;
    }
};

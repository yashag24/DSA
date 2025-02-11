//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
      int rows=grid.size();
      int columns=grid[0].size();
      vector<vector<int>>vis(rows,vector<int>(columns,0));
      queue<pair<int,int>>q;
      
      for(int i=0;i<rows;i++){
          for(int k=0;k<columns;k++){
              if(i==0 || k==0 || i==rows-1 || k ==columns-1){
                  if(grid[i][k]==1){
                        q.push({i,k});
                        vis[i][k]=1;
                    }
                }
            }
        }
        
        int delr[]={1,0,-1,0};
        int delc[]={0,-1,0,1};
        
        while(!q.empty()){
            int curr=q.front().first;
            int curc=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr=curr+delr[i];
                int nc=curc+delc[i];
                if(nr>=0 && nc>=0&& nr<rows&& nc<columns && !vis[nr][nc] && grid[nr][nc]==1){
                vis[nr][nc]=1;
                q.push({nr,nc});
                }
            }
        }
      
 
        int count=0;
    
        for(int i =0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(!vis[i][j] && grid[i][j]==1)
                    count++;
            }
        }
      return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
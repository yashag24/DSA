//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{       
   
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
 vector<vector<int>>nearest(vector<vector<int>>grid)
	{  
	   int rows=grid.size();
	   int columns=grid[0].size();
	   vector<vector<int>>vis(rows,vector<int>(columns,0));
	   vector<vector<int>>ans(rows,vector<int>(columns,-1));
	   
	   queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<rows;i++){
            for(int j =0;j<columns;j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
         vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
        int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1};
            while(!q.empty()){
                int curR=q.front().first.first;
                int curC=q.front().first.second;
                int dist=q.front().second;
                ans[curR][curC]=dist;
                q.pop();
            
               for(int i = 0;i<4;i++) {
	            int nrow = curR + delrow[i]; 
	            int ncol = curC + delcol[i]; 
	            // check for valid unvisited cell
	            if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < columns 
	            && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
	                q.push({{nrow, ncol}, dist+1});  
	            }
	        }
   
            }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
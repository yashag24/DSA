//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
//vector<vector<int>>&image,
   void dfs(vector<vector<int>>&vis,vector<vector<int>>&ans ,int row,int col,int newColor,int iniColor){
       ans[row][col]=newColor;
       vis[row][col]=1;
       int rows=ans.size();
       int columns=ans[0].size();
       
       vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
       for(auto dir:directions){
           int nr = row+dir.first;
           int nc= col + dir.second;
           
           if(nr>=0&&nc>=0&&nr<rows && nc<columns && !vis[nr][nc]){
               if(ans[nr][nc]==iniColor){
                   ans[nr][nc]=newColor;
                   vis[nr][nc]=1;
                   dfs(vis,ans,nr,nc,newColor,iniColor);
               }
           }
       }
       
       
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            int rows=image.size();
            int columns=image[0].size();
            vector<vector<int>>vis(rows,vector<int>(columns,0));
           vector<vector<int>>ans=image;
           int iniColor=image[sr][sc];
           dfs(vis,ans,sr,sc,newColor,iniColor);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
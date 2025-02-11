//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    void dfs(vector<vector<char>>&mat,int r , int c,vector<vector<int>>&vis){
        vis[r][c]=1;
        int n=mat.size();
        int m=mat[0].size();
        int delr[]={0,-1,0,1};
        int delc[]={-1,0,1,0};
        
        for(int i =0;i<4;i++){
            int nr=r+delr[i];
            int nc=c+delc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && mat[nr][nc]=='O'){
                vis[nr][nc]=1;
                dfs(mat,nr,nc,vis);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        
        
       
            for(int j=0;j<m;j++){
                if( !vis[0][j] && mat[0][j]=='O' ){
                    dfs(mat,0,j,vis);
                }
                if(!vis[n-1][j] && mat[n-1][j]=='O'){
                    
                    dfs(mat,n-1,j,vis);
                }
            }
            for(int j=0;j<n;j++){
                if( !vis[j][0] && mat[j][0]=='O' ){
                    dfs(mat,j,0,vis);
                }
                if(!vis[j][m-1] && mat[j][m-1]=='O'){
                    
                    dfs(mat,j,m-1,vis);
                }
            }
                
                
         
        
        
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    vis[i][j]=1;
                    mat[i][j]='X';
                }
                
                
            }
        }
        return mat;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
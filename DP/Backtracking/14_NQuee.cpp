#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool issafe(int row, int col, vector<string> &board, int n)
    {

        int dr = row;
        int dc = col;

        while (dr >= 0 && dc >= 0)
        {
            if (board[dr][dc] == 'Q')
                return false;
            dr--;
            dc--;
        }

        dr = row;
        dc = col;
        while (dc >= 0)
        {
            if (board[dr][dc] == 'Q')
                return false;
            dc--;
        }
        dr = row;
        dc = col;
        while (dr < n && dc >= 0)
        {
            if (board[dr][dc] == 'Q')
                return false;
            dr++;
            dc--;
        }

        return true;
    }

    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (issafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);

        solve(0, ans, board, n);

        return ans;
    }
};

///////////////////Hashing////////////
 void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n,vector<bool>left,vector<bool>UD,vector<bool>LD){
        if(col==n)
        {
            ans.push_back(board);
            return;
        }

        for(int row =0;row<n;row++){

            if(left[row]==0 && LD[row+col]==0 && UD[n-1+col-row]==0){
                board[row][col]='Q';
                left[row]=1;
                LD[row+col]=1;
                UD[n-1+col-row]=1;
                solve(col+1,ans,board,n,left,UD,LD);
                board[row][col]='.';
                left[row]=0;
                LD[row+col]=0;
                UD[n-1+col-row]=0;


            }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);
        vector<bool> left(n,0),upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
        solve(0, ans, board, n,left,upperdiagonal,lowerdiagonal);

        return ans;
    }
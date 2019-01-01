//
// Created by zhao on 19-1-1.
//

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

//class Solution {
//public:
//    void solve(vector<vector<char>>& board) {
//        queue<pair<int,int>> q;
//        int m=board.size(),n=board[0].size();
//        vector<vector<int>> visited(m,vector<int>(n,0));
//        bool cover=true;
//        for(int i=0;i<m;++i)
//        {
//            for(int j=0;j<n;++j)
//            {
//                if(board[i][j]=='O' && visited[i][j]==0)
//                {
//                    visited[i][j]=1;
//                    if(i==0 || i==m-1 || j==0 || j==n-1)
//                        cover=false;
//
//
//                }
//            }
//        }
//    }
//
//    void findsourending(queue<int> &que,vector<vector<char>>& board,int row,int col)
//    {
//
//    }
//};


class Solution2 {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;
        int m=board.size(),n=board[0].size();
        for(int i=0;i!=m;++i)
            for(int j=0;j!=n;++j)
            {
                if((i==0 || i==m-1 || j==0 || j==n-1 ) && board[i][j]=='O')
                    dfshelper(board,i,j);
            }
        for(int i=0;i!=m;++i)
            for(int j=0;j!=n;++j)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='*')
                    board[i][j]='O';
            }
    }
    void dfshelper(vector<vector<char>>& board,int a,int b)
    {
        board[a][b]='*';
        if(a>0 && board[a-1][b]=='O')
            dfshelper(board,a-1,b);
        if(a<board.size()-1 && board[a+1][b]=='O')
            dfshelper(board,a+1,b);
        if(b>0 && board[a][b-1]=='O')
            dfshelper(board,a,b-1);
        if(b<board[0].size() && board[a][b+1]=='O')
            dfshelper(board,a,b+1);
    }
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;
        int m=board.size(),n=board[0].size();
        queue<int> q;
        for(int i=0;i!=m;++i)
            for(int j=0;j!=n;++j)
            {
                if(i!=0 && i!=m-1 && j!=0 && j!=n-1)
                    continue;
                if(board[i][j]!='O')
                    continue;
                board[i][j]='*';
                q.push(i*n+j);

                while(!q.empty())
                {
                    int x=q.front()/n,y=q.front()%n;
                    q.pop();
                    if(x>0 && board[x-1][y]=='O')
                    {
                        board[x-1][y]='*';
                        q.push((x-1)*n+y);
                    }
                    if(x<m-1 && board[x+1][y]=='O')
                    {
                        board[x+1][y]='*';
                        q.push((x+1)*n+y);
                    }
                    if(y>0 && board[x][y-1]=='O') {
                        board[x][y-1]='*';
                        q.push(x * n + y - 1);
                    }
                    if(y<n-1 && board[x][y+1]=='O') {
                        board[x][y+1]='*';
                        q.push(x * n + y + 1);
                    }
                }
            }

        for(int i=0;i!=m;++i)
            for(int j=0;j!=n;++j)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='*')
                    board[i][j]='O';
            }
    }
};

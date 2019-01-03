//
// Created by zhao on 19-1-3.
//

#include <iostream>
#include <vector>
using namespace std;




class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int n=grid.size(),m=grid[0].size();
        int islandnum=0;
        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i=0;i!=n;++i)
            for(int j=0;j!=m;++j)
            {
                if(grid[i][j]=='1' && v[i][j]==0) {
                    helper(grid, i, j, v);
                    ++islandnum;
                }
            }
        return islandnum;
    }

    void helper(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &v)
    {
        v[i][j]=1;
        if(i>0 && grid[i-1][j]=='1' && v[i-1][j]==0)
            helper(grid, i - 1, j, v);
        if(j>0 && grid[i][j-1]=='1' && v[i][j-1]==0)
            helper(grid, i, j - 1, v);
        if(i<grid.size()-1 && grid[i+1][j]=='1' && v[i+1][j]==0)
            helper(grid, i + 1, j, v);
        if(j<grid[0].size()-1 && grid[i][j+1]=='1' && v[i][j+1]==0)
            helper(grid, i, j + 1,v);
    }
};


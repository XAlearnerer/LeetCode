#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int n = grid.size(), m = grid[0].size();
		vector<vector<int> > vis(n, vector<int>(m, 0));
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] == '1' && vis[i][j] == 0)
				{
					helper(grid, vis, i, j);
					++res;
				}
			}
		}
		return res;
	}

	void helper(vector<vector<char>>& grid, vector<vector<int> >& vis, int i, int j)
	{
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
		if (vis[i][j] == 1 || grid[i][j] == '0') return;
		vis[i][j] = 1;
		helper(grid, vis, i + 1, j);
		helper(grid, vis, i - 1, j);
		helper(grid, vis, i, j + 1);
		helper(grid, vis, i, j - 1);
	}

};


#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;



//最开始想的是对于每个点都来搜索是否能到达边缘，只不过搜索的目标点不再是一个单点，
//而是所有的边缘点，照这种思路写出的代码无法通过 OJ 大数据集，那么就要想办法来优化代码，
//优化的方法跟之前那道 Surrounded Regions 很类似，都是换一个方向考虑问题，
//既然从每个点向中间扩散会 TLE，那么我们就把所有边缘点当作起点开始遍历搜索，
//然后标记能到达的点为 true，分别标记出 pacific 和 atlantic 能到达的点，
//那么最终能返回的点就是二者均为 true 的点



class Solution {
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return {};
		vector<pair<int, int>> res;
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<bool>> pacific(m, vector<bool>(n, false));
		vector<vector<bool>> atlantic(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i) {
			dfs(matrix, pacific, INT_MIN, i, 0);
			dfs(matrix, atlantic, INT_MIN, i, n - 1);
		}
		for (int i = 0; i < n; ++i) {
			dfs(matrix, pacific, INT_MIN, 0, i);
			dfs(matrix, atlantic, INT_MIN, m - 1, i);
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (pacific[i][j] && atlantic[i][j]) {
					res.push_back({ i, j });
				}
			}
		}
		return res;
	}

	void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int pre, int i, int j)
	{
		int m = matrix.size(), n = matrix[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || matrix[i][j] < pre) return;
		visited[i][j] = true;
		dfs(matrix, visited, matrix[i][j], i + 1, j);
		dfs(matrix, visited, matrix[i][j], i - 1, j);
		dfs(matrix, visited, matrix[i][j], i, j + 1);
		dfs(matrix, visited, matrix[i][j], i, j - 1);
	}

};


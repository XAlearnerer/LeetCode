#include<iostream>
#include<vector>

using namespace std;


///////// BFS ///////////
//? worng
class Solution_worng {  //与island不同
public:
	int findCircleNum(vector<vector<int>>& M) {
		int m = M.size(), n = M[0].size();
		int res = 0;
		vector<vector<int>> visited(m, vector<int>(n, 0));
		for (int i = 0; i != m; ++i)
		{
			for (int j = 0; j != n; ++j)
			{
				if (M[i][j] == 1 && visited[i][j] == 0)
				{
					helper(M, visited, i, j);
					++res;
				}
			}
		}
		return res;
	}

	void helper(vector<vector<int>> M, vector<vector<int>>& visited,int i,int j)
	{
		if (i<0 || j<0 || i>M.size() - 1 || j>M[0].size() - 1) return;
		if (visited[i][j] == 1 || M[i][j] == 0) return;
		visited[i][j] = 1;
		helper(M, visited, i + 1, j);
		helper(M, visited, i - 1, j);
		helper(M, visited, i, j + 1);
		helper(M, visited, i, j - 1);

	}
};

///////// DFS ///////////

class Solution2 {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int m = M.size();
		int res = 0;
		vector<int> v(m, 0);
		for (int i = 0; i != m; ++i)
		{
			if (v[i] == 1) continue;
			helper(M,v,i);
			++res;
		}
		return res;
	}

	void helper(vector<vector<int>> M, vector<int>& v, int i)
	{
		v[i] = 1;
		for (int j = 0; j != M.size(); ++j)
		{
			if (v[j] == 1 || M[i][j] == 0) continue;
			helper(M, v, j);
		}
	}
};



////// UnionFind //////


class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		vector<int> root(n);
		for (int i = 0; i != n; ++i)
		{
			root[i] = i;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (M[i][j] == 1)
				{
					int p = find(root, i);
					int q = find(root, j);
					if (p != q) root[p] = q;
				}
			}
		}
		int res = 0;
		for (int i = 0; i != n; ++i)
		{

			//  这里 之前的 root[i] 的值均修改为之后的值，若未改变则说明不同的 圈

			//   1 0 0 1
			//   0 1 1 0
			//   0 1 1 1
			//   0 1 0 0
			     
			//   root值：3 2 3 3


			if (i == root[i]) ++res;
		}
		return res;
	}

	int find(vector<int>& root,int i)
	{
		while (i != root[i]) {
			root[i] = root[root[i]];
			i = root[i];
		}
		return i;
	}
};






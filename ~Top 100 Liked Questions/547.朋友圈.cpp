#include<iostream>
#include<vector>

using namespace std;

class Solution1 {
public:
	int findCircleNum(vector<vector<int>>& M) {
		if (M.empty()) return 0;
		int n = M.size();
		vector<int> v(n, 0);
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			if (v[i] == 1) continue;
			helper(M, v, i);
			++res;
		}
		return res;
	}

	void helper(vector<vector<int>> M, vector<int>& v, int i)
	{
		v[i] = 1;
		for (int j = 0; j < M.size(); ++j)
		{
			if (v[j] == 1 || M[i][j] == 0) continue;
			helper(M, v, j);
		}
	}

};


/////////////////////////////////////////////////////////////////////////////


class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		if (M.empty()) return 0;
		int n = M.size();
		vector<int> root(n);
		for (int i = 0; i < n; ++i)
			root[i] = i;

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
		for (int i = 0; i < n; ++i)
			if (i == root[i]) ++res;
		return res;
	}

	int find(vector<int>& root, int i)
	{
		while (i != root[i])
		{
			root[i] = root[root[i]];
			i = root[i];
		}
		return i;
	}


};




#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> v = vector<vector<int>>(m, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
		{
			if (matrix[0][i] == '1') v[0][i] = 1;
		}
		for (int i = 1; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == '1') v[i][j] = 1 + v[i - 1][j];
			}
		}

		int res = 0;
		for (int i = 0; i < m; ++i)
			res = max(res, helper(v[i]));
		return res;
	}

	int	helper(vector<int> &heights)
	{
		stack<int> t;
		int i = 0;
		int lararea = 0;
		while (i < heights.size())
		{
			if (t.empty() || heights[i] >= heights[t.top()])
			{
				t.push(i);
				++i;
			}
			else
			{
				int p = t.top();
				t.pop();
				int cur = 0;
				if (t.empty()) cur = heights[p] * i;
				else cur = heights[p] * (i - t.top() - 1);
				lararea = max(lararea, cur);
			}
		}

		while (!t.empty())
		{
			int p = t.top();
			t.pop();
			int cur = 0;
			if (t.empty()) cur = heights[p] * i;
			else cur = heights[p] * (i - t.top() - 1);
			lararea = max(lararea, cur);
		}

		return lararea;
	}
};

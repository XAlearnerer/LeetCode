#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		if (n <= 0) return{};
		vector<vector<string>> res;
		vector<int> solve(n, -1);
		helper(n, res, 0, solve);
		return res;
	}

	void helper(int n, vector<vector<string>>& res, int k, vector<int>& solve)
	{
		if (k == n)
		{
			string s(n, '.');
			vector<string> v(n, s);
			for (int i = 0; i < n; ++i)
			{
				v[i][solve[i]] = 'Q';
			}
			res.push_back(v);
			return;
		}

		for (int i = 0; i < n; ++i)
		{
			solve[k] = i;
			if (check(solve, k)) helper(n, res, k + 1, solve);
		}
	
	}

	bool check(vector<int>& solve,int k)
	{
		for (int i = 0; i < k; ++i)
		{
			if (solve[i] == solve[k]) return false;
			if (abs(solve[i] - solve[k]) == abs(i - k)) return false;
		}
		return true;
	}

};


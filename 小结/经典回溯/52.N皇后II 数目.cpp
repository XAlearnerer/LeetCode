#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		if (n <= 0) return{};
		int res = 0;
		vector<int> solve(n, -1);
		helper(n, 0, solve, res);
		return res;
	}

	void helper(int n, int k, vector<int>& solve,int& res)
	{
		if (k == n)
		{
			++res;
			return;
		}
		for (int i = 0; i < n; ++i)
		{
			solve[k] = i;
			if (check(solve, k)) helper(n, k + 1, solve, res);
		}
	}

	bool check(vector<int>& solve,int k)
	{
		for (int i = 0; i < k; ++i)
		{
			if (solve[k] == solve[i]) return false;
			if (abs(k - i) == abs(solve[k] - solve[i])) return false;
		}
		return true;
	}

};


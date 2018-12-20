#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
#include<string>

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> solve(n, -1);
		vector<vector<string>> res;
		Nqueen(solve, 0, n, res);
		return res;

	}

	void Nqueen(vector<int>& solve, int k, int n, vector<vector<string>>& res)
	{
		if (k == n)
		{
			string s(n, '.');
			vector<string> vs(n, s);
			for (int i = 0; i != n; ++i)
			{
				vs[i][solve[i]] = 'Q';
			}
			res.push_back(vs);
			
			for (auto j : solve)
				cout << j << " ";
			cout << endl;

			return;
		}
		for (int i = 0; i != n; ++i)
		{
			solve[k] = i;
			if (check(solve, k, n))
				Nqueen(solve, k + 1, n, res);
		}
	}

	bool check(vector<int>& solve, int k, int n)
	{
		for (int i = 0; i != k; ++i)
		{
			if (solve[k] == solve[i]) return false;
			if (abs(k - i) == abs(solve[k] - solve[i])) return false;
		}

		return true;
	}
};

int main1635()
{
	Solution n;
	vector<vector<string> >vv = n.solveNQueens(4);
	for (auto i : vv) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}
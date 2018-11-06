#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
#include<string>

class Solution {
public:
	int totalNQueens(int n) {
		vector<int> solve(n, -1);
		int nums = 0;
		Nqueen(0, n,solve, nums);
		return nums;

	}

	void Nqueen(int k, int n, vector<int>& solve,int &nums)
	{
		if (k == n)
		{
			++nums;
			return;
		}
		for (int i = 0; i != n; ++i)
		{
			solve[k] = i;
			if (check(solve, k, n))
				Nqueen(k + 1, n, solve, nums);
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

int main1640()
{
	Solution n;
	cout << n.totalNQueens(4) << endl;
	return 0;
}
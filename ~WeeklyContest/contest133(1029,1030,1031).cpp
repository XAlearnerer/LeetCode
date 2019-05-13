#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <queue>
#include <string>
#include <set>

using namespace std;


class Solution1029 {
public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		if (costs.empty()) return 0;
		int n = costs.size() / 2;
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		// i -> A & j -> B
		for (int i = 1; i <= n; ++i)
			dp[i][0] = dp[i - 1][0] + costs[i - 1][0];
		for (int i = 1; i <= n; ++i)
			dp[0][i] = dp[0][i - 1] + costs[i - 1][1];

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dp[i][j] = min(dp[i - 1][j] + costs[i + j - 1][0], dp[i][j - 1] + costs[i + j - 1][1]);
			}
		}

		//for (auto i : dp)
		//{
		//	for (auto j : i)
		//		cout << j << " ";
		//	cout << endl;
		//}
		return dp[n][n];
	}
};


/////////////////////////////////////


class Solution1030 {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int>> res;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				res.push_back({ i,j });
			}
		}

		//sort(res.begin(), res.end(), [](vector<int> v1,vector<int> v2, int r0, int c0)
		//{return (abs(v1[0] - r0) + abs(v1[1] - c0))<(abs(v2[0] - r0) + abs(v2[1] - c0)); });

		auto comp = [r0, c0](vector<int> &a, vector<int> &b)
		{
			return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
		};
		sort(res.begin(), res.end(), comp);
/*

sort(res.begin(), res.end(), [r0, c0](vector<int> v1,vector<int> v2)
{return (abs(v1[0] - r0) + abs(v1[1] - c0))<(abs(v2[0] - r0) + abs(v2[1] - c0)); });

*/
		return res;
	}
};



/////////////////////////////////////

class Solution1031 {
public:
	int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
		for (int i = 1; i < A.size(); ++i)
			A[i] += A[i - 1];
		int lmax = A[L - 1], mmax = A[M - 1];
		
		// int res = 0;
		//		[1, 0, 3]
		//		1
		//		2

		int res = A[L + M - 1];
		for (int i = L + M; i < A.size(); ++i)
		{
			lmax = max(lmax, A[i - M] - A[i - L - M]);
			mmax = max(mmax, A[i - L] - A[i - L - M]);
			res = max(res,max(lmax + A[i] - A[i - M], mmax + A[i] - A[i - L]));
		}

		return res;
	}
};


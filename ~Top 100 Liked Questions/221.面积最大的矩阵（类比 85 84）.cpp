#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//  dp[i][j] 表示 右下角为 [i][j] 的点的最大的正方形的边长


class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<int>> dp(n, vector<int>(m, 0));
		int res = 0;
		for (int i = 0; i < n; ++i) if (matrix[i][0] == '1') { dp[i][0] = 1; res = max(dp[i][0], res); }
		for (int i = 0; i < m; ++i) if (matrix[0][i] == '1') { dp[0][i] = 1; res = max(dp[0][i], res); }

		//int res = 0;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j < m; ++j)
			{
				if (matrix[i][j] == '1')
				{
					dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
					res = max(dp[i][j], res);
				}
			}
		}

		return res*res;
	}
};

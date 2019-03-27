#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//	int maximalSquare(vector<vector<char>>& matrix) {
//		if (matrix.empty()) return 0;
//		int n = matrix.size(), m = matrix[0].size();
//		vector<vector<int>> dp(n, vector<int>(m, 0));
//		for (int i = 0; i != n; ++i)
//			dp[i][0] = matrix[i][0] == 1 ? 1 : 0;
//		for (int i = 0; i != m; ++i)
//			dp[0][i] = matrix[0][i] == 1 ? 1 : 0;
//		int maxsquare = 0;
//		for (int i = 1; i != n; ++i)
//		{
//			for (int j = 1; j != m; ++j)
//			{
//				if (matrix[i][j] == 0)
//					dp[i][j] = 0;
//				else
//					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
//				maxsquare = max(maxsquare, dp[i][j]);
//			}
//		}
//		return maxsquare*maxsquare;
//	}
//};

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int maxsquare = 0;
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<int>> dp(n, vector<int>(m, 0));
		for (int i = 0; i != n; ++i)
		{
			dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
			maxsquare = max(maxsquare, dp[i][0]);
		}
		for (int i = 0; i != m; ++i)
		{
			dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
			maxsquare = max(maxsquare, dp[0][i]);
		}

		for (int i = 1; i != n; ++i)
		{
			for (int j = 1; j != m; ++j)
			{
				if (matrix[i][j] == '0')
					dp[i][j] = 0;
				else
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				maxsquare = max(maxsquare, dp[i][j]);
			}
		}

		return maxsquare*maxsquare;
	}
};

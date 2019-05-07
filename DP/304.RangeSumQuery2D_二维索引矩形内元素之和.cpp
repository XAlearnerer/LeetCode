#include<iostream>
#include<vector>
using namespace std;

class NumMatrix_worng { //? worng 减去的值多了一行一列
public:
	NumMatrix_worng(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i != m; ++i) dp.push_back(vector<int>(n, 0));
		dp[0][0] = matrix[0][0];
		for (int i = 1; i != m; ++i) dp[i][0] = matrix[i][0];
		for (int j = 1; j != n; ++j) dp[0][j] = matrix[0][j];
		for (int i = 1; i != m; ++i)
		{
			for (int j = 1; j != n; ++j)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return dp[row2][col2] - (dp[row1][col2] + dp[row2][col1] - dp[row1][col1]);

	}
	vector<vector<int>> dp;
};

class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {

		if (matrix.empty() || matrix[0].empty()) return;

		int m = matrix.size(), n = matrix[0].size();
		dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
		//dp[0][0] = matrix[0][0];
		//for (int i = 1; i != m; ++i) dp[i][0] = matrix[i][0];
		//for (int j = 1; j != n; ++j) dp[0][j] = matrix[0][j];
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return dp[row2 + 1][col2 + 1] - (dp[row1][col2 + 1] + dp[row2 + 1][col1] - dp[row1][col1]);

	}
	vector<vector<int>> dp;
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix* obj = new NumMatrix(matrix);
* int param_1 = obj->sumRegion(row1,col1,row2,col2);
*/
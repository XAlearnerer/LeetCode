#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	int minimumTotal(vector<vector<int>>& triangle) {
//		if (triangle.empty()) return 0;
//		int len = triangle.size();
//		vector<int> d(len, 0), p(len, 0);
//		d[0] = triangle[0][0];
//		for (int i = 1; i != len; ++i)
//		{
//			if (triangle[i][p[i - 1]] > triangle[i][p[i - 1] + 1])
//			{
//				d[i] = d[i - 1] + triangle[i][p[i - 1] + 1];
//				p[i] = p[i - 1] + 1;
//			}
//			else
//			{
//				d[i] = d[i - 1] + triangle[i][p[i - 1]];
//				p[i] = p[i - 1];
//			}
//		}
//	
//		return d[len - 1];
//	}
//};

//Wrong Answer
//Details
//Input
//[[-1], [2, 3], [1, -1, -3]]
//Output
//0
//Expected
//- 1

//===============================================



class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		int len = triangle.size();
		vector<vector<int>> dp(len, vector<int>(len, 0));
		dp[0][0] = triangle[0][0];
		for (int i = 1; i != len; ++i)
		{
			for (int j = 0; j != i + 1; ++j)
			{
				if (j == 0)
					dp[i][j] = dp[i - 1][j] + triangle[i][0];
				else if (j == i)
					dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
				else
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
			}
		}

		sort(dp[len - 1].begin(), dp[len - 1].end());
		return dp[len - 1][0];
	}
};
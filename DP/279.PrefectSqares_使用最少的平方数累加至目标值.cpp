#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//====================dp=========================
//例如： dp[18] 时，需要找到{ dp[18 - 1], dp[18 - 4], dp[18 - 9], dp[18 - 16] } 中的最小值

class Solution {
public:
	int numSquares(int n) {
		if (n <= 0)return 0;
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j*j <= i; ++j)
			{
				dp[i] = min(dp[i], dp[i - j*j] + 1);
			}
		return dp[n];
	}
};





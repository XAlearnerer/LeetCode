#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	int getMoneyAmount(int n) {
		if (n <= 1) return 0;
		if (n == 2) return 1;

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		int local = 0, global = 0;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = i - 1; j > 0; --j)
			{
				global = INT_MAX;
				for (int k = j + 1; k < i; ++k)
				{
					local = max(dp[j][k - 1], dp[k + 1][i]) + k;
					global = min(global, local);
				}
				if (j + 1 == i) dp[j][i] = j;
				else dp[j][i] = global;
			}
		}

		return dp[1][n];
	}
};







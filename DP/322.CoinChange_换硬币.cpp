#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i)
		{
			//dp[i] = INT_MAX;
			for (int j = 0; j != coins.size(); ++j)
			{
				if (i >= coins[j])
				{
					dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
				}
			}
		}
		if (dp[amount] == amount + 1) return -1;

		return dp[amount];
	}
};


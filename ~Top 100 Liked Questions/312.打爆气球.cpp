#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = nums.size();
		nums.push_back(1);
		nums.insert(nums.begin(), 1);
		vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));

		for (int len = 1; len <= n; ++len)
		{
			for (int i = 1; i + len < n + 2; ++i)
			{
				int j = i + len - 1;
				for (int k = i; k <= j; ++k)
				{
					dp[i][j] = max(dp[i][j],
						dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]);

//dp[i][k-1] 的意义是什么呢，是打爆区间 [i, k-1] 内所有的气球后的最大得分，
//此时第 k-1 个气球已经不能用了，同理，第 k+1 个气球也不能用了，
//相当于区间 [i, j] 中除了第k个气球，其他的已经爆了，
//那么周围的气球只能是第 i-1 个，和第 j+1 个了，所以得分应为 nums[i-1] * nums[k] * nums[j+1]
				}
			}
		}

		return dp[1][n];

	}
};

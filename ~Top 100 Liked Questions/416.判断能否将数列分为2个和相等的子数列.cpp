#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (auto i : nums) sum += i;
		if (sum % 2 != 0) return false;
		int target = sum / 2;
		vector<bool> dp(target + 1, false);
		// dp[i]表示原数组是否可以取出若干个数字，其和为i。
		dp[0] = true;

		for (auto i : nums)
		{
			for (int j = target; j >= i; --j)
			{
				dp[j] = dp[j] || dp[j - i];
			}
		}

		return dp[target];
	}
};






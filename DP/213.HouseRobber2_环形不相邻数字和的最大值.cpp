#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;




class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		vector<int> v1, v2;
		v1.assign(nums.begin() + 1, nums.end());
		v2.assign(nums.begin(), nums.end() - 1);
		return max(helper(v1), helper(v2));
	}

	int helper(vector<int>& nums)
	{
		int len = nums.size();
		if (len == 1)return nums[0];
		if (len == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
		if (len == 3)return nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		dp[1] = nums[1];
		dp[2] = nums[0] + nums[2];
		int m = max(dp[1], dp[2]);
		for (int i = 3; i < nums.size(); ++i)
		{
			dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
			if (dp[i] > m)
				m = dp[i];
		}

		return m;
	}
};
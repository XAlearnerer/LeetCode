#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution2 {   //worng  [2,1,1,2]
public:
	int rob(vector<int>& nums) {
		int rob1 = 0, rob2 = 0;
		for (int i = 0; i != nums.size(); ++i)
		{
			if (i % 2 == 0)
			{
				rob1 += nums[i];
			}
			else
				rob2 += nums[i];
		}
		if (rob1 > rob2)
			return rob1;
		else
			return rob2;
	}
};



class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
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
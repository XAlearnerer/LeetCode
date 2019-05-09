#include<iostream>
#include<vector>

using namespace std;



////////////// recursion ///////////////////
class Solution2 {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int res = 0;
		helper(nums, 0, 0, res, S);
		return res;
	}

	void helper(vector<int>& nums, int cur, int n, int& res, int t)
	{
		if (n == nums.size())
		{
			if (cur == t) ++res;
			return;
		}

		helper(nums, cur + nums[n], n + 1, res, t);
		helper(nums, cur - nums[n], n + 1, res, t);
	}
};



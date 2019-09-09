#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		helper(nums, res, 0);
		return res;
	}

	void helper(vector<int>& nums, vector<vector<int>>& res, int t)
	{
		if (t >= nums.size()) res.push_back(nums);
		else
		{
			for (int i = t; i < nums.size(); ++i)
			{
				swap(nums[i], nums[t]);
				helper(nums, res, t + 1);
				swap(nums[i], nums[t]);
			}
		}
	}
};


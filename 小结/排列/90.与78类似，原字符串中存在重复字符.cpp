#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		
		/////////////////

		sort(nums.begin(), nums.end());

		/////////////////

		vector<vector<int>> res;
		vector<int> n;
		helper(res, nums, n, 0);
		return res;
	}

	void helper(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, int pos)
	{
		res.push_back(cur);
		for (int i = pos; i < nums.size(); ++i)
		{
			//if (i > 0 && nums[i] == nums[i - 1]) continue;
			if (i > pos && nums[i] == nums[i - 1]) continue;

			cur.push_back(nums[i]);
			helper(res, nums, cur, i + 1);
			cur.pop_back();
		}
	}

};


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution_2 {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) return 0;
		int res = nums[0], mn = nums[0], mx = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			int tmx = mx, tmn = mn;

			mx = max(max(tmx*nums[i], tmn*nums[i]), nums[i]);
			mn = min(min(tmx*nums[i], tmn*nums[i]), nums[i]);

			res = max(mx, res);
		}

		return res;
	}
};



class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) return 0;
		int res = nums[0], cur = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			cur *= nums[i];
			res = max(res, cur);
			if (nums[i] == 0) cur = 1;
		}

		cur = 1;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			cur *= nums[i];
			res = max(res, cur);
			if (nums[i] == 0) cur = 1;
		}

		return res;
	}
};


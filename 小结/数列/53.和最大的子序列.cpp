#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;
		int res = INT_MIN;
		int cur = 0;
		for (auto i : nums)
		{
			cur = max(i, cur + i);
			res = max(res, cur);
		}

		return res;
	}
};



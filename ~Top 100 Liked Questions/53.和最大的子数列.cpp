#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		if (nums.empty()) return 0;
//		int res = nums[0], sta = 0, cur = 0;
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			cur += nums[i];
//			if (cur < 0)
//			{
//				cur = 0;
//			}
//			else
//			{
//				res = max(res, cur);
//			}
//		}
//
//		return res;
//	}
//};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;
		int res = nums[0], sta = 0, cur = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			cur += nums[i];
			res = max(res, cur);
			if (cur < 0)
			{
				cur = 0;
			}

		}

		return res;
	}
};



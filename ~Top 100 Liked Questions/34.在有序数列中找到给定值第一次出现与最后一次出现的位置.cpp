#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) return { -1,-1 };
		int len = nums.size();
		int l = 0, r = len - 1;
		int m = -1;
		bool e = false;
		while (l <= r)
		{
			m = l + (r - l) / 2;
			if (nums[m] == target) { e = true; break; }
			else if (nums[m] < target) l = m + 1;
			else r = m - 1;
		}
		if (!e) return{ -1,-1 };
		int m1 = m;
		while (m > 0 && nums[m] == nums[m - 1]) --m;
		while (m1 < len - 1 && nums[m1] == nums[m1 + 1]) ++m1;

		return { m,m1 };
	}
};
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;
		int len = nums.size();
		int l = 0, r = len - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] == target) return m;
			
			/*else if (nums[m] > target)
			{
				if (nums[m] > nums[l])
				{
					r = m - 1;
				}
				else
				{
					l = m + 1;
				}
			}
			else
			{
				if (nums[m] > nums[l])
				{
					l = m + 1;
				}
				else
				{
					r = m - 1;
				}
			}*/

			if (nums[m] >= nums[l])
			{
				if (nums[m] > target && nums[l] <= target) r = m - 1;
				else l = m + 1;
			}
			else
			{
				if (nums[m] < target && nums[r] >= target) l = m + 1;
				else r = m - 1;
			}
		}
		return -1;
	}
};

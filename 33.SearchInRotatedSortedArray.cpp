#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			/*else if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				if (nums[left] == target)
					return left;
				else if (nums[left] < target)
					right = mid - 1;
				else
					left = mid + 1;
			}*/
			if (nums[left] <= nums[right])
			{
				if (target < nums[mid]) right = mid - 1;
				else
					left = mid + 1;
			}
			else if (nums[left] <= nums[mid])
			{
				if (target > nums[mid] || target < nums[left])
					left = mid + 1;
				else
					right = mid - 1;
			}
			else
			{
				if (target < nums[mid] || target>nums[right])
					right = mid - 1;
				else
					left = mid + 1;

			}
		}

		return -1;

	}
};


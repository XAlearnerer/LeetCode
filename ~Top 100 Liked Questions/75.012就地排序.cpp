#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.empty()) return;
		int i = 0, j = nums.size() - 1;
		int pos = 0;
		//while (i < j)
		//{
		//	while (nums[i] == 0) ++i;
		//	while (nums[j] == 2) --j;
		//	swap(nums[i], nums[j]);
		//}

		while (pos <= j)
		{
			if (nums[pos] == 1) ++pos;
			else if (nums[pos] == 0)
			{
				swap(nums[pos], nums[i]);
				++i; ++pos;
			}
			else
			{
				swap(nums[pos], nums[j]);
				//++pos;
				--j;
			}

		}

	}
};


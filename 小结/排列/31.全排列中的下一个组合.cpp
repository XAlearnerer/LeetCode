#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.empty()) return;
		for (int i = nums.size() - 2; i >= 0; --i)
		{
			if (nums[i] < nums[i + 1])
			{
				//for (int j = i + 1; j < nums.size(); ++j)
				for (int j = nums.size() - 1; j >= 0; --j)
				{
					if (nums[i] < nums[j])
					{
						swap(nums[i], nums[j]);
						break;
					}
				}
				reverse(nums.begin() + i + 1, nums.end());
				return;
			}
		}

		reverse(nums.begin(), nums.end());
	}
};




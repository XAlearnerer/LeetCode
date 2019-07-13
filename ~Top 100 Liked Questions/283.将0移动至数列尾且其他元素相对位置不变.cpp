#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int pos = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != 0)
			{
				swap(nums[i], nums[pos]);
				++pos;
			}
		}

		for (; pos < nums.size(); ++pos)
			nums[pos] = 0;
	}
};

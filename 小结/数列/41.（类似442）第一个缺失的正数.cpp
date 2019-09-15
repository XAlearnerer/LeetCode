﻿#include<iostream>
#include<vector>

using namespace std;


//但是上面的解法不是O(1)的空间复杂度，所以我们需要另想一种解法，
//既然不能建立新的数组，那么我们只能覆盖原有数组，我们的思路是把1放在数组第一个位置nums[0]，
//2放在第二个位置nums[1]，即需要把nums[i]放在nums[nums[i] - 1]上，
//那么我们遍历整个数组，如果nums[i] != i + 1, 而nums[i]为整数且不大于n，
//另外nums[i]不等于nums[nums[i] - 1]的话，我们将两者位置调换，
//如果不满足上述条件直接跳过，最后我们再遍历一遍数组，如果对应位置上的数不正确则返回正确的数


class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1) return i + 1;
		}
		return n + 1;
	}
};
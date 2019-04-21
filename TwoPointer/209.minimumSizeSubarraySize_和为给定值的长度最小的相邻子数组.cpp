#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int i = 0, j = 0;
		int len = nums.size() + 1;
		int sum = 0;
		while (j != nums.size())
		{
			while (j != nums.size() && sum < s)
			{
				sum += nums[j];
				++j;
			}
			while (sum >= s)
			{
				len = min(len, j - i);
				sum -= nums[i];
				++i;
			}
		}
		if (len == nums.size() + 1) return 0;
		else
			return len;

	}
};
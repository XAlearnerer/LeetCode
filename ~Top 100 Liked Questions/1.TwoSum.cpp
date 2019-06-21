#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (m.count(target - nums[i]))
				return { i,m[target - nums[i]] };
			else
				m[nums[i]] = i;
		}
		return {};
	}
};


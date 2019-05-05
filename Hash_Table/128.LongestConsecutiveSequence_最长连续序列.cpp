#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

//Your algorithm should run in O(n) complexity.

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> s(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0; i != nums.size(); ++i)
		{
			if (s.find(nums[i]) == s.end()) continue;
			int pre = nums[i] - 1;
			int post = nums[i] + 1;
			while (s.find(pre) != s.end()) s.erase(pre--);
			while (s.find(post) != s.end()) s.erase(post++);
			res = max(res, post - pre - 1);
		}
		return res;
	}
};
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		unordered_set<int> t(nums.begin(), nums.end());
		int res = 0;
		for (auto i : nums)
		{
			if (!t.count(i)) continue;
			int pre = i - 1, post = i + 1;
			t.erase(i);
			while (t.count(pre) != 0) --pre;
			while (t.count(post) != 0) ++post;
			res = max(res, post - pre - 1);

		}

		return res;
	}
};



/////////////////////////////////////

class Solution2 {
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
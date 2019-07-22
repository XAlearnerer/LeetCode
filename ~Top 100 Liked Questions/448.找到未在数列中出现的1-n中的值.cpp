#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		if (nums.empty()) return {};
		unordered_set<int> s;
		for (auto i : nums) s.insert(i);
		int n = nums.size();
		vector<int> res;
		for (int i = 1; i <= n; ++i)
		{
			if (s.count(i) == 0) res.push_back(i);
		}
		return res;
	}
};






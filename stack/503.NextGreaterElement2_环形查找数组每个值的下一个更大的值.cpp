#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution2 {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i != nums.size(); ++i)
		{
			int j;
			if (i == nums.size() - 1) j = 0;
			else j = i + 1;

			int prel = res.size();
			while (j != i)
			{
				if (nums[j] > nums[i])
				{
					res.push_back(nums[j]);
					break;
				}
				if (j == nums.size() - 1) j = 0;
				else ++j;
			}
			if (prel == res.size()) res.push_back(-1);
		}

		return res;
	}
};




class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		stack<int> s;
		vector<int> res(nums.size(), -1);
		for (int i = 0; i != nums.size() * 2; ++i)
		{
			int cur = nums[i%nums.size()];
			while (!s.empty() && cur > nums[s.top()])
			{
				res[s.top()] = cur;
				s.pop();
			}

			if (i < nums.size()) s.push(i);
		}

		return res;
	}
};




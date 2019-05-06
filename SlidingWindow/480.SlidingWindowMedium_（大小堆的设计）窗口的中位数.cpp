#include<iostream>
#include<vector>
#include<deque>
#include<set>

using namespace std;


//维护两个堆，multiset自动排序

class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		multiset<int> large, small;
		vector<double> res;

		for (int i = 0; i != nums.size(); ++i)
		{
			if (i >= k)
			{
				if (large.count(nums[i - k])) large.erase(large.find(nums[i - k]));
//? worng
//if (small.count(nums[i - k])) small.erase(small.find(nums[i - k]));
				else if (small.count(nums[i - k])) small.erase(small.find(nums[i - k]));
			}
			if (small.size() <= large.size())
			{
				if (large.empty() || nums[i] <= *large.begin()) small.insert(nums[i]);
				else
				{
					small.insert(*large.begin());
					large.erase(large.begin());
					large.insert(nums[i]);
				}
			}
			else
			{
				if (nums[i] >= *small.rbegin()) large.insert(nums[i]);
				else
				{
					large.insert(*small.rbegin());
					//small.erase(small.rbegin());
					small.erase(--small.end());
					small.insert(nums[i]);
				}
			}

			if (i >= k - 1)
			{
				if (k % 2) res.push_back(*small.rbegin());
				else res.push_back(((double)*small.rbegin() + *large.begin()) / 2);
			}
		}

		return res;
	}
};




class Solution2 {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		vector<double> res;
		multiset<double> ms(nums.begin(), nums.begin() + k);
		auto mid = next(ms.begin(), k / 2);
		for (int i = k; ; ++i) {
			res.push_back((*mid + *prev(mid, 1 - k % 2)) / 2);
			if (i == nums.size()) return res;
			ms.insert(nums[i]);
			if (nums[i] < *mid) --mid;
			if (nums[i - k] <= *mid) ++mid;
			ms.erase(ms.lower_bound(nums[i - k]));
		}
	}
};


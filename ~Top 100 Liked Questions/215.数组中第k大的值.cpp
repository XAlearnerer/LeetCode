#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

//
//
//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		if (nums.size() == 1) return nums[0];
//		for (int i = 1; i < nums.size(); ++i)
//		{
//			for (int j = i - 1; j >= 0; --j)
//			{
//				if (nums[j] < nums[j + 1]) swap(nums[j + 1], nums[j]);
//			}
//			if (k == i + 1) return nums[i];
//		}
//		return -1;
//	}
//};
//
//



class Solution2 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		make_heap(nums.begin(), nums.end());
		int res = nums[0];
		for (int i = 0; i < k; ++i)
		{
			pop_heap(nums.begin(), nums.end());
			res = nums.back();
			nums.pop_back();

		}
		return res;

	}
};


class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue <int> q(nums.begin(), nums.end());
		int res = nums[0];
		for (int i = 0; i < k; ++i)
		{
			res = q.top();
			q.pop();
		}
		return res;


	}
};



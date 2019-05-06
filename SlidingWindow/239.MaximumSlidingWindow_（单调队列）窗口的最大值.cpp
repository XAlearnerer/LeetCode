#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> q;
		vector<int> res;
		for (int i = 0; i != nums.size(); ++i)
		{
			if (!q.empty() && i - q.front() == k) q.pop_front();
			while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
			q.push_back(i);
			if (i >= k - 1) res.push_back(nums[q.front()]);
		}
		return res;
	}
};

//int main()
//{
//	vector<int> v = { 1,3,-1,-3,5,3,6,7 };
//	int k = 3;
//	Solution n;
//	n.maxSlidingWindow(v, k);
//	return 0;
//}
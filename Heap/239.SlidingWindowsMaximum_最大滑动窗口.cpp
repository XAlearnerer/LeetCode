//
// Created by zhao on 19-4-9.
//

#include <iostream>
#include <vector>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;


// Could you solve it in linear time?

//这道题给定了一个数组，还给了一个窗口大小k，让我们每次向右滑动一个数字，
//每次返回窗口内的数字的最大值，而且要求我们代码的时间复杂度为O(n)。
//提示我们要用双向队列deque来解题，并提示我们窗口中只留下有用的值，没用的全移除掉。
//
//大概思路是用双向队列保存数字的下标，遍历整个数组，如果此时队列的首元素是i - k的话，
//表示此时窗口向右移了一步，则移除队首元素。然后比较队尾元素和将要进来的值，
//如果小的话就都移除，然后此时我们把队首元素加入结果中即可，

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> d;

    }
};


class Solution2 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		deque<int> q;
		for (int i = 0; i < nums.size(); ++i) {
			if (!q.empty() && q.front() == i - k) q.pop_front();
			while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
			q.push_back(i);
			if (i >= k - 1) res.push_back(nums[q.front()]);
		}
		return res;
	}
};

class Solution3 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int size = nums.size();
		vector<int> ans;
		if (size == 0) return nums;
		for (int i = 0; i < 1 + size - k; i++) {
			int temp = INT_MIN;
			for (int j = i; j < i + k; j++) {
				temp = max(temp, nums[j]);
			}
			ans.push_back(temp);
		}
		return ans;
	}
};



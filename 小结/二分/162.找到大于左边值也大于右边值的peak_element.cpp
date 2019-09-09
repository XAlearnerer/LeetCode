#include<iostream>
#include<vector>

using namespace std;


//那么我们就要考虑使用类似于二分查找法来缩短时间，由于只是需要找到任意一个峰值，
//那么我们在确定二分查找折半后中间那个元素后，和紧跟的那个元素比较下大小，
//如果大于，则说明峰值在前面，如果小于则在后面。这样就可以找到一个峰值


class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] < nums[mid + 1]) left = mid + 1;
			else right = mid;
		}
		return right;
	}
};



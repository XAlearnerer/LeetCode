//Given an array which consists of non - negative integers and an integer m,
//you can split the array into m non - empty continuous subarrays.
//Write an algorithm to minimize the largest sum among these m subarrays.
//
//Note:
//If n is the length of array, assume the following constraints are satisfied :
//
//1 ≤ n ≤ 1000
//1 ≤ m ≤ min(50, n)
//Examples :
//
//Input :
//nums = [7, 2, 5, 10, 8]
//m = 2
//
//Output :
//18
//
//Explanation :
//There are four ways to split nums into two subarrays.
//The best way is to split it into[7, 2, 5] and [10, 8],
//where the largest sum among the two subarrays is only 18.


//给一个数组，将其分成n部分，使其每部分的和尽可能的接近
//（题目中给出的条件是，使其中和最大的一组数，和最小）。
//
//隐藏的比较深一点，其实也是一个背包问题，只不过是二维费用问题，即隐藏了一个背包放置数量为n / 2个
//
//dp[i][count][sum] = max{ dp[i - 1][count - 1][sum - a[i]] , dp[i - 1][count][sum] };
//
//仿一维背包问题，将其优化成一个二维数组





#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


   
   
// 只能上网参考大神们的解法，发现大家普遍使用了二分搜索法来做，感觉特别巧妙，
// 原来二分搜索法还能这么用，厉害了我的哥。
// 首先来分析，如果m和数组 nums 的个数相等，那么每个数组都是一个子数组，所以返回 nums 中最大的数字即可，
// 如果m为1，那么整个 nums 数组就是一个子数组，返回 nums 所有数字之和，所以对于其他有效的m值，
// 返回的值必定在上面两个值之间，所以可以用二分搜索法来做。
// 
// 用一个例子来分析，nums = [1, 2, 3, 4, 5], m = 3，将 left 设为数组中的最大值5，
// right 设为数字之和 15，然后算出中间数为 10，接下来要做的是找出和最大且小于等于 10 的子数组的个数，
// [1, 2, 3, 4], [5]，可以看到无法分为3组，说明 mid 偏大，所以让 right = mid，然后再次进行二分查找，
// 算出 mid = 7，再次找出和最大且小于等于7的子数组的个数，[1, 2, 3], [4], [5]，成功的找出了三组，
// 说明 mid 还可以进一步降低，让 right = mid，再次进行二分查找，算出 mid = 6，
// 再次找出和最大且小于等于6的子数组的个数，[1, 2, 3], [4], [5]，成功的找出了三组，
// 尝试着继续降低 mid，让 right = mid，再次进行二分查找，算出 mid = 5，
// 再次找出和最大且小于等于5的子数组的个数，[1, 2], [3], [4], [5]，发现有4组，
// 此时的 mid 太小了，应该增大 mid，让 left = mid + 1，此时 left = 6，right = 5，循环退出了，
// 返回 right 即可，
   


class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		long long sum = 0;
		for (auto i : nums) sum += i;
		long long mx = *max_element(nums.begin(), nums.end());

  //?     =========     不能排序     =========
		//sort(nums.begin(), nums.end());
		//long long mx = nums.back();   
		//long long left = nums.back(), right = sum;

		long long left = mx;
		long long right = sum;
		while (left < right)
		{
			long long  mid = left + (right - left) / 2;
			if (helper(nums, m, mid)) right = mid;
			else left = mid + 1;
		}
		return right;
	}

	bool helper(vector<int>& nums, int m, long long sum) {
		long long cnt = 1, curSum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			curSum += nums[i];
			if (curSum > sum) {
				curSum = nums[i];
				++cnt;
				if (cnt > m) return false;
			}
		}
		return true;
	}
};










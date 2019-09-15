//Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
//Formally the function should :
//
//Return true if there exists i, j, k
//such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n - 1 else return false.
//Note : Your algorithm should run in O(n) time complexity and O(1) space complexity.
//
//Example 1 :
//
//Input : [1, 2, 3, 4, 5]
//Output : true
//Example 2 :
//
//Input : [5, 4, 3, 2, 1]
//Output : false



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int one = INT_MAX, two = INT_MAX;
		for (auto i : nums)
		{
			if (one > i) one = i;
			else if (two > i) two = i;
			else return true;
		}
		return false;
	}
};

//
//如果觉得上面的解法不容易想出来，那么如果能想出下面这种解法，估计面试官也会为你点赞。这种方法的虽然不满足常数空间的要求，但是作为对暴力搜索的优化，也是一种非常好的解题思路。这个解法的思路是建立两个数组，forward数组和backward数组，其中forward[i]表示[0, i]之间最小的数，backward[i]表示[i, n - 1]之间最大的数，那么对于任意一个位置i，如果满足 forward[i] < nums[i] < backward[i]，则表示这个递增三元子序列存在，举个例子来看吧，比如：
//
//	nums :		8  3  5  1  6
//
//	foward :	8  3  3  1  1
//
//	backward :  8  6  6  6  6
//
//我们发现数字5满足forward[i] < nums[i] < backward[i]，所以三元子序列存在。
//

#include<iostream>
#include<vector>

using namespace std;


//Given a non - empty array containing only positive integers, 
//find if the array can be partitioned into two subsets such that the sum of elements in both subsets
//is equal.
//
//
//Note:
//
//Each of the array element will not exceed 100.
//The array size will not exceed 200.
//
//
//Example 1:
//Input: [1, 5, 11, 5]
//Output : true
//Explanation : The array can be partitioned as[1, 5, 5] and [11].
//
//
//Example 2 :
//Input : [1, 2, 3, 5]
//Output : false
//Explanation : The array cannot be partitioned into equal sum subsets.
//
//
//原数组所有数字和一定是偶数，不然根本无法拆成两个和相同的子集合，
//那么我们只需要算出原数组的数字之和，然后除以2，就是我们的target，
//那么问题就转换为能不能找到一个非空子集合，使得其数字之和为target。



class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (auto a : nums) sum += a;
		if (sum % 2 != 0) return false;
		int target = sum / 2;
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = target; j >= nums[i]; --j)
			{
				dp[j] = dp[j] || dp[j - nums[i]];
			}
		}
		return dp[target];
	}
};


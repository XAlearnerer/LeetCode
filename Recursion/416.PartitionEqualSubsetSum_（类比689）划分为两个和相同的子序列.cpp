#include<iostream>
#include<vector>


using namespace std;



class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (auto i : nums)
			sum += i;
		if (sum % 2 != 0) return false;
		int target = sum / 2;
		vector<bool> dp(target + 1, false);
		dp[0] = true;
		for (auto i : nums)
		{
			for (int j = target; j >= i; --j)
			{
				dp[j] = dp[j] || dp[j - i];
			}
		}
		return dp[target];
	}
};







//  动态规划 Dynamic Programming 就是我们的不二之选。
//  我们定义一个一维的dp数组，其中dp[i]表示原数组是否可以取出若干个数字，其和为i。

//  那么我们最后只需要返回dp[target]就行了。初始化dp[0]为true，
//  由于题目中限制了所有数字为正数，那么就不用担心会出现和为0或者负数的情况。
//  关键问题就是要找出状态转移方程了，我们需要遍历原数组中的数字，
//  对于遍历到的每个数字nums[i]，需要更新dp数组，我们的最终目标是想知道dp[target]的boolean值，
//  就要想办法用数组中的数字去凑出target，因为都是正数，所以只会越加越大，
//  那么加上nums[i]就有可能会组成区间[nums[i], target] 中的某个值，
//  那么对于这个区间中的任意一个数字j，如果 dp[j - nums[i]] 为true的话，
//  说明现在已经可以组成 j - nums[i] 这个数字了，再加上nums[i]，就可以组成数字j了，
//  那么dp[j]就一定为true。如果之前dp[j]已经为true了，当然还要保持true，所以还要‘或’上自身，
//  于是状态转移方程如下：
//  
//  dp[j] = dp[j] || dp[j - nums[i]](nums[i] <= j <= target)
//  
//  有了状态转移方程，那么我们就可以写出代码了，这里需要特别注意的是，
//  第二个for循环一定要从target遍历到nums[i]，而不能反过来，想想为什么呢？
//  因为如果我们从nums[i]遍历到target的话，假如nums[i] = 1的话，
//  那么[1, target]中所有的dp值都是true，因为dp[0]是true，dp[1]会或上dp[0]，为true，
//  dp[2]会或上dp[1]，为true，依此类推，完全使我们的dp数组失效了，参见代码如下：

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//其中f[i]表示子数组[0, i]范围内并且一定包含nums[i]数字的最大子数组乘积，
//g[i]表示子数组[0, i]范围内并且一定包含nums[i]数字的最小子数组乘积，
//初始化时f[0]和g[0]都初始化为nums[0]，其余都初始化为0。
//那么从数组的第二个数字开始遍历，那么此时的最大值和最小值只会在这三个数字之间产生，
//即f[i - 1] * nums[i]，g[i - 1] * nums[i]，和nums[i]。所以我们用三者中的最大值来更新f[i]，
//用最小值来更新g[i]，然后用f[i]来更新结果res即可，由于最终的结果不一定会包括nums[n - 1]这个数字，
//所以f[n - 1]不一定是最终解，不断更新的结果res才是，


class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = nums.size();
		vector<int> f(n, 0);
		vector<int> g(n, 0);
		f[0] = g[0] = nums[0];
		int res = nums[0];
		for (int i = 1; i != nums.size(); ++i)
		{
			f[i] = max(f[i - 1] * nums[i], max(g[i - 1] * nums[i], nums[i]));
			g[i] = min(f[i - 1] * nums[i], min(g[i - 1] * nums[i], nums[i]));
			if (f[i] > res)
				res = f[i];
		}
		return res;
	}
};
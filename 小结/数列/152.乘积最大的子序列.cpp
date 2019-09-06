#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



//f[i]表示子数组[0, i]范围内并且一定包含nums[i]数字的最大子数组乘积，
//g[i]表示子数组[0, i]范围内并且一定包含nums[i]数字的最小子数组乘积，
//初始化时f[0]和g[0]都初始化为nums[0]，其余都初始化为0。
//那么从数组的第二个数字开始遍历，那么此时的最大值和最小值只会在这三个数字之间产生，
//即f[i - 1] * nums[i]，g[i - 1] * nums[i]，和nums[i]。


class Solution_2 {
public:
	int maxProduct(vector<int>& nums) {
		int res = nums[0], n = nums.size();
		vector<int> f(n, 0), g(n, 0);
		f[0] = nums[0], g[0] = nums[0];
		for (int i = 1; i < n; ++i)
		{
			f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
			g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
			res = max(res, f[i]);
		}

		return res;
	}
};

//int main()
//{
//	vector<int> v = { 0,2 };
//	Solution n;
//	cout << n.maxProduct(v) << endl;
//
//	return 0;
//}


/////////////////////////////////////////////////////////////////


//这种解法遍历了两次，一次是正向遍历，一次是反向遍历，
//相当于正向建立一个累加积数组，每次用出现的最大值更新结果res，
//然后再反响建立一个累加积数组，再用出现的最大值更新结果res，
//注意当遇到0的时候，prod要重置为1。至于为啥正反两次遍历就可以得到正确的结果了呢？
//主要还是由于负数个数的关系，因为负数可能会把最大值和最小值翻转，
//那么当有奇数个负数时，如果只是正向遍历的话，可能会出错，
//比如[-1, -2, -3]，我们累加积会得到 - 1，2， - 6，
//看起来最大值只能为2，其实不对，而如果我们再反向来一遍，累加积为 - 3，6， - 6，
//就可以得到6了。
//所以当负数个数为奇数时，首次出现和末尾出现的负数就很重要，
//有可能会是最大积的组成数字，所以遍历两次就不会漏掉组成最大值的机会，



class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int res = nums[0];
		int cur = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			res = max(res, cur = nums[i] * cur);
			if (nums[i] == 0) cur = 1;
		}
		cur = 1;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			res = max(res, cur = nums[i] * cur);
			if (nums[i] == 0) cur = 1;
		}

		return res;
	}
};



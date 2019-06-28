#include<iostream>
#include<vector>

using namespace std;

//class Solution {
//public:
//	int numTrees(int n) {
//		if (n == 0) return 0;
//		if (n == 1) return 1;
//		long re = helper(n);
//		return re / (n + 1);
//
//	}
//
//	int f(int i)
//	{
//		if (i == 1 || i == 0) return 1;
//		else
//		{
//			return i*f(i - 1);
//		}
//	}
//
//	//int helper(int n)
//	//{
//	//	return f(2 * n) / f(n) / f(n);
//	//}
//
//	long helper(int n)
//	{
//		long l = 1;
//		for (int i = n + 1; i <= 2 * n; ++i)
//			l *= i;
//		return l / f(n);
//
//	}
//
//};

//Áîh(0) = 1, h(1) = 1£¬catalanÊýÂú×ãµÝÍÆÊ½[1]£º
//h(n) = h(0)*h(n - 1) + h(1)*h(n - 2) + ... + h(n - 1)h(0) (n >= 2)

class Solution {
public:
	int numTrees(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		vector<int> dp(n + 1, 0);
		dp[0] = 1, dp[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 0; j < i; ++j)
				dp[i] += dp[j] * dp[i - 1 - j];
		}

		return dp[n];
	}

};


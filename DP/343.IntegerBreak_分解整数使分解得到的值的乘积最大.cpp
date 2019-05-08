#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//	int integerBreak(int n) {
//		vector<int> dp(n + 1, 0);
//		dp[2] = 1;
//		for (int i = 3; i <= n; ++i)
//		{
//			
//		}
//	}
//};


class Solution {
public:
	int integerBreak(int n) {
		if (n == 2 || n == 3) return n - 1;
		int res = 1;
		while (n > 4) {
			res *= 3;
			n -= 3;
		}
		return res * n;
	}
};


class Solution2 {
public:
	int integerBreak(int n) {
		vector<int> dp{ 0, 0, 1, 2, 4, 6, 9 };
		for (int i = 7; i <= n; ++i) {
			dp.push_back(3 * dp[i - 3]);
		}
		return dp[n];
	}
};


//正整数从1开始，但是1不能拆分成两个正整数之和，所以不能当输出。
//那么2只能拆成1 + 1，所以乘积也为1。
//数字3可以拆分成2 + 1或1 + 1 + 1，显然第一种拆分方法乘积大为2。
//数字4拆成2 + 2，乘积最大，为4。
//数字5拆成3 + 2，乘积最大，为6。
//数字6拆成3 + 3，乘积最大，为9。
//数字7拆为3 + 4，乘积最大，为12。
//数字8拆为3 + 3 + 2，乘积最大，为18。
//数字9拆为3 + 3 + 3，乘积最大，为27。
//数字10拆为3 + 3 + 4，乘积最大，为36。


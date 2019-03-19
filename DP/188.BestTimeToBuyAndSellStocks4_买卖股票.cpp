#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//但这道题还有个坑，就是如果k的值远大于prices的天数，比如k是好几百万，
//而prices的天数就为若干天的话，上面的DP解法就非常的没有效率

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int days = prices.size();

		if (k > days) return maxp2(prices);

		vector<vector<int>> global(days, vector<int>(k + 1, 0));
		vector<vector<int>> local(days, vector<int>(k + 1, 0));
		for (int i = 1; i != days; ++i)
		{
			int dif = prices[i] - prices[i - 1];
			for (int j = 1; j <= k; ++j)
			{
				local[i][j] = max(global[i - 1][j - 1] + max(0, dif), local[i - 1][j] + dif);
				global[i][j] = max(global[i - 1][j], local[i][j]);
			}
		}
		return global[days - 1][k];
	}

	int maxp2(vector<int>& prices)
	{
		int start = 0, end = 1;
		int sum = 0;
		while (end < prices.size())
		{
			if (prices[end] > prices[start])
			{
				sum += prices[end] - prices[start];
			}
			start = end;
			++end;
		}
		return sum;

	}
};



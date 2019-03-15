#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// https://blog.csdn.net/fightforyourdream/article/details/14503469

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		vector<vector<int>> l(len, vector<int>(3, 0)), g(len, vector<int>(3, 0));
		
		for (int i = 1; i != prices.size(); ++i)
		{
			int d = prices[i] - prices[i - 1];
			for (int j = 1; j <= 2; ++j)
			{
				l[i][j] = max(l[i - 1][j] + d, g[i - 1][j - 1] + max(d, 0));  //max（d，0） 0表示在 i 天买入又卖出
				g[i][j] = max(g[i - 1][j], l[i][j]);
			}
		}
		return g[len - 1][2];
	}
};


//局部（在第i天交易后，总共交易了j次） = max{ 情况2，情况1 }
//
//情况1：在第i - 1天时，恰好已经交易了j次（local[i - 1][j]），那么如果i - 1天到i天再交易一次：
//即在第i - 1天买入，第i天卖出（diff），则这不并不会增加交易次数！【例如我在第一天买入，第二天卖出；
//然后第二天又买入，第三天再卖出的行为  和   第一天买入，第三天卖出  的效果是一样的，其实只进行了一次交易！因为有连续性】
//
//情况2：第i - 1天后，共交易了j - 1次（global[i - 1][j - 1]），因此为了满足“第i天过后共进行了j次交易，
//且第i天必须进行交易”的条件：我们可以选择1：在第i - 1天买入，然后再第i天卖出（diff），
//或者选择在第i天买入，然后同样在第i天卖出（收益为0）。

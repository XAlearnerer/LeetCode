#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int buyp = INT_MAX, finp = 0;
		for (int i=0;i!=prices.size();++i)
		{
			buyp = min(buyp, prices[i]);
			finp = max(finp, prices[i] - buyp);
		}
		return finp;
	}
};







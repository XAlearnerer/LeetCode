#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

//
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		if (prices.empty()) return 0;
//		stack<int> t;
//		for (int i = 0; i < prices.size(); ++i)
//		{
//			if (t.empty()) t.push(i);
//			while (!t.empty() && prices[t.top()] > prices[i])
//			{
//				t.pop();
//			}
//			t.push(i);
//
//		}
//
//		if (t.size() == 1) return 0;
//		int r = t.top(); t.pop();
//		int l = -1;
//		while (!t.empty())
//		{
//			l = t.top();
//			t.pop();
//		}
//		cout << prices[l] << " -- " << prices[r] << endl;
//		return prices[r] - prices[l];
//	}
//};


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int res = 0, cur = INT_MAX;
		for (int i = 0; i < prices.size(); ++i)
		{
			cur = min(cur, prices[i]);
			res = max(res, prices[i] - cur);
		}
		return res;
	}
};


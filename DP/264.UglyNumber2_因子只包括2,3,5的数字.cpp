#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//	int nthUglyNumber(int n) {
//		int i = 1, j = 1, k = 1;
//		int ri = 2, rj = 3, rk = 5;
//		int turn = 1;
//		int res = 1;
//		//int minq = 0;
//		while (turn <= n)
//		{
//			res = min(ri, min(rj, rk));
//			if (res == ri)
//			{
//				++i;
//				ri = 2 * i;
//			}
//			else if (res == rj)
//			{
//				++j;
//				rj = 3 * j;
//			}
//			else
//			{
//				++k;
//				rk = 5 * k;
//			}
//			++turn;
//		}
//		return res;
//
//	}
//};

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> res(1, 1);
		int i = 0, j = 0, k = 0;
		while (res.size() < n)
		{
			res.push_back(min(min(res[i] * 2, res[j] * 3), res[k] * 5));
			if (res.back() == res[i] * 2) ++i;
			if (res.back() == res[j] * 3) ++j;
			if (res.back() == res[k] * 5) ++k;
		}
		return res.back();
	}
};


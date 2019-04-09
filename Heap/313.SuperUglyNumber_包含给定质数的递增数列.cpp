#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	int nthSuperUglyNumber(int n, vector<int>& primes) {
//		vector<int> res;
//		res.push_back(1);
//		vector<int> it(primes.size(), 1);
//		while (res.size() < n)
//		{
//			int minP = INT_MAX, minI = -1;
//			for (int i = 0; i != primes.size(); ++i)
//			{
//				if (primes[i] * it[i] < minP)
//				{
//					minP = primes[i] * it[i];
//					minI = i;
//				}
//			}
//
//			res.push_back(minP);
//			++it[minI];
//		}
//		return res.back();
//	}
//};

class Solution { /////注意有可能最小值不止一个，要更新所有最小值的位置
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> it(primes.size(), 0);
		vector<int> res;
		res.push_back(1);

		while (res.size() < n)
		{
			vector<int> temp(primes.size());
			for (int i = 0; i != primes.size(); ++i)
			{
				temp[i] = res[it[i]] * primes[i];
			}
			int minP = INT_MAX;
			//for (int i = 0; i != primes.size(); ++i)
			//{
			//	if (temp[i] < minP)
			//	{
			//		minP = temp[i];
			//	}
			//}
			for (int i = 0; i != primes.size(); ++i)
			{
				minP = min(minP, temp[i]);
			}
			for (int i = 0; i != primes.size(); ++i)
			{
				if (minP == temp[i])
					++it[i];
			}
			res.push_back(minP);
		}
		return res.back();
	}
};

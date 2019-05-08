#include<iostream>
#include<vector>

using namespace std;


class Solution2 {
public:
	vector<int> countBits(int num) {
		vector<int> res;
		res.push_back(0);
		if (num == 0) return res;
		res.push_back(1);
		if (num == 1) return res;

		int p = 2, i = 2;
		while (i <= num)
		{
			for (i = pow(2, p - 1); i < pow(2, p); ++i)
			{
				if (i > num) break;
				int pos = (pow(2, p) - pow(2, p - 1)) / 2;
				if (i < pow(2, p - 1) + pos) res.push_back(res[i - pos]);
				else res.push_back(res[i - pos] + 1);
			}
			++p;
		}
		return res;
	}
};


class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res(num + 1, 0);
		for (int i = 0; i <= num; ++i)
		{
			if (i % 2 == 0) res[i] = res[i / 2];
			else res[i] = res[i / 2] + 1;
		}
		return res;
	}
};

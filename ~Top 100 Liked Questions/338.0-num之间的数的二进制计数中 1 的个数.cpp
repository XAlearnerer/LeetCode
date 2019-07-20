#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//!  0    0000    0
//!  ------------ -
//!  1    0001    1
//!  ------------ -
//!  2    0010    1
//!  3    0011    2
//!  ------------ -
//!  4    0100    1
//!  5    0101    2
//!  6    0110    2
//!  7    0111    3
//!  ------------ -
//!  8    1000    1
//!  9    1001    2
//!  10   1010    2
//!  11   1011    3
//!  12   1100    2
//!  13   1101    3
//!  14   1110    3
//!  15   1111    4



class Solution {
public:
	vector<int> countBits(int num) {
		if (num <= 0) return { 0 };
		if (num == 1) return { 0,1 };
		vector<int> v;
		v.push_back(0);
		v.push_back(1);
		int p = 2, i = 2;
		while (i <= num)
		{
			for (i = pow(2, p - 1); i < pow(2, p); ++i)
			{
				if (i>num) break;
				int pos = (pow(2, p) - pow(2, p - 1)) / 2;
				if (i < pos + pow(2, p - 1)) v.push_back(v[i - pos]);
				else v.push_back(v[i - pos] + 1);
			}
			++p;
		}
		return v;


	}
};


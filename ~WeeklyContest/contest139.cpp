#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <map>

using namespace std;

class Solution1071 {
public:
	string gcdOfStrings(string str1, string str2) {
		if (str1.empty() || str2.empty()) return "";
		int res = 0;
		for (int i = 1; i <= min(str1.size(),str2.size()); ++i)
		{
			if (str1.size() % i == 0 && str2.size() % i == 0)
			{
				string cur = str1.substr(0, i);
				string a, b;
				for (int p = 0; p < str1.size() / i; ++p) a += cur;
				for (int q = 0; q < str2.size() / i; ++q) b += cur;
				if (a == str1 && b == str2) res = i;
			}
		}
		return str1.substr(0, res);

		//string s, l;
		//if (str1.size() < str2.size()) { s = str1; l = str2; }
		//else { s = str2; l = str1; }

		//if (search(l.begin(), l.end(), s.begin(), s.end()) == l.end()) return "";
		//else
		//{

		//}

	//	vector<int> v(26, 0);
	//	for (auto i : s) ++v[i - 'A'];
	//	sort(v.begin(), v.end());
	//	if (v[0] == 1) return s;
	//	else
	//	{
	//		int times = v[0];
	//		if (s.size() % v[0] != 0) return s;
	//		else
	//		{
	//			int pos = 0;
	//			while (s.size() / v[0] + pos < s.size())
	//			{
	//				if (s[pos] == s[s.size() / v[0] + pos])
	//					++pos;
	//				else return s;
	//			}
	//			return s.substr
	//		}
	//	}

	}
};


//////////////////////////////////////////////////////////////////////////


//  e.g.1
//  000     110
//  001 ->  111 <-all ones
//	110     000 <-all zeros
//	       ^^
//	       flip columns
//
//	e.g.2
//	00111       11111 <-all ones
//	11000       00000 <-all zeros
//	10101  ->   01101
//	10100       01100
//	00111       11111 <-all ones
//			   ^^
//			   flip columns
//
//	now we look closer, actually row0, row1 and row4 have the same pattern originally
//	row0 = 00111
//	row1 = 11000
//	row4 = 00111
//
//	so we can just flip the rows count the pattern occurrence 
//  instead of brainlessly flipping the columns
//


class Solution {
public:
	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {



	}
};















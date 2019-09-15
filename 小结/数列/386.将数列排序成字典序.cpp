
//Given an integer n, return 1 - n in lexicographical order.
//
//For example, given 13, return: [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9].
//
//Please optimize your algorithm to use less time and space.
//The input size may be as large as 5, 000, 000.


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<int> v;
		for (int i = 1; i <= n; ++i)
			v.push_back(i);
		sort(v.begin(), v.end(), [](int a, int b)
		{
			return to_string(a) < to_string(b);
		});
		return v;
	}
};







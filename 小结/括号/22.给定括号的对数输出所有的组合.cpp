#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n <= 0) return {};
		vector<string> res;
		helper(n, n, res, "");
		return res;
	}

	void helper(int l,int r,vector<string>& res,string cur)
	{
		if (l == 0 && r == 0)
		{
			res.push_back(cur);
			return;
		}
		if (l > r) return;
		if (l > 0) helper(l - 1, r, res, cur + '(');
		if (r > 0) helper(l, r - 1, res, cur + ')');
	}

};


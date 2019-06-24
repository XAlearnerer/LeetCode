
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution_ha {
public:
	string longestPalindrome(string s) {
		if (s.empty()) return "";
		if (s.size() == 1) return s;
		int pos = 0, len = 0;
		for (int i = 0; i < s.size() - 1; ++i)
		{
			helper(s, i, i, pos, len);
			helper(s, i, i + 1, pos, len);
		}
		return s.substr(pos, len);
	}

	void helper(string s, int l, int r, int& pos, int& len)
	{
		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			--l; ++r;
		}

		if (r - l - 1 > len)
		{
			pos = l + 1;
			len = r - l - 1;
		}
	}
};


class Solution {
public:
	string longestPalindrome(string s) {
		string cur = "$#";
		for (int i = 0; i < s.size(); ++i) {
			cur += s[i];
			cur += "#";
		}

		vector<int> p(cur.size(), 0);
		int id = 0, mx = 0;
		int resid = 0, reslen = 0;

		for (int i = 1; i < cur.size(); ++i)
		{
			if (mx > i) p[i] = min(p[2 * id - i], mx - i);
			else p[i] = 1;
			while (cur[p[i] + i] == cur[i - p[i]]) ++p[i];

			if (p[i] + i > mx)
			{
				mx = p[i] + i;
				id = i;
			}
			if (reslen < p[i])
			{
				reslen = p[i];
				resid = i;
			}
		}

		return s.substr((resid - reslen) / 2, reslen - 1);
	}
};





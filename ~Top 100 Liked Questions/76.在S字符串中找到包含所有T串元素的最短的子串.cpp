#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> v(256, 0);
		//for (auto i : t) ++v[i - 'a'];
		for (auto i : t) ++v[i];

		int l = 0, count = 0, minlen = INT_MAX;
		string res = "";
		for (int i = 0; i < s.size(); ++i)
		{
			if (--v[s[i]] >= 0) ++count;
			while (count == t.size())
			{
				if (i - l + 1 < minlen)
				{
					minlen = i - l + 1;
					res = s.substr(l, minlen);
				}
				if (++v[s[l]] > 0) --count;
				++l;
			}
		}

		return res;
	}
};



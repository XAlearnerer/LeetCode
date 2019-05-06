#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
	string minWindow(string s, string t) {
		
		//vector<char> v(256, 0);
		vector<int> v(256, 0);

		for (auto i : t)
			++v[i];
		string res = "";
		int left = 0, cur = 0, reslen = INT_MAX;
		for (int i = 0; i != s.length(); ++i)
		{
			if (--v[s[i]] >= 0) ++cur;
			while (cur==t.length())
			{
				int len = i - left + 1;
				if (reslen > len)
				{
					reslen = len;
					res = s.substr(left, reslen);
				}
				if (++v[s[left]] > 0) --cur;
				++left;
			}
		}


		return res;
	}
};
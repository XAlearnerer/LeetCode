#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<int, int> m;
		int i = 0;
		int begin = 0;
		int res = 0;
		while (i < s.length())
		{
			if (m.count(s[i]) != 0)
			{
				if (m[s[i]] >= begin)
				{
					begin = m[s[i]] + 1;
				}
			}
			res = max(res, i - begin + 1);
			m[s[i]] = i;
			++i;
		}
		return res;
	}
};


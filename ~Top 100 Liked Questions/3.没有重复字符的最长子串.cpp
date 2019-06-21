#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty()) return 0;
		if (s.size() == 1) return 1;

		vector<int> vis(256, -1);
		int res = 1;
		int begin = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (vis[s[i]] != -1)
			{
				if (vis[s[i]] >= begin)
				{
					begin = vis[s[i]] + 1;
				}
			}
			vis[s[i]] = i;
			res = max(res, i - begin + 1);
		}

		return res;
	}
};
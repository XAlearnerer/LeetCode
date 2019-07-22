#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() < 2) return 0;
		stack<int> t;
		int i = 0;
		int res = 0, sta = 0;
		while (i < s.size())
		{
			if (s[i] == '(') { t.push(i); ++i; }
			else
			{
				if (t.empty()) { sta = i + 1; }
				else
				{
					t.pop();
					if (!t.empty())
						res = max(res, i - t.top());
					else
					{
						res = max(res, i - sta + 1);
					}
				}
				++i;
			}
		}

		return res;
	}
};


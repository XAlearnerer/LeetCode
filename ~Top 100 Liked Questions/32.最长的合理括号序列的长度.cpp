#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> t;
		int res = 0; 
		int sta = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(') t.push(i);
			else
			{
				if (t.empty())
				{
					sta = i + 1;
				}
				else
				{
					t.pop();
					if (t.empty())
					{
						res = max(res, i - sta + 1);
					}
					else
						res = max(res, i - t.top());
				}
			}
		}

		return res;

	}
};


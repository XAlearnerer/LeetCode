#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
	int scoreOfParentheses(string S) {
		stack<int> sta;
		sta.push(0);
		for (auto i : S)
		{
			if (i == '(')
			{
				sta.push(0);
			}
			else
			{
				int t = sta.top();
				sta.pop();
				if (t == 0) sta.top() += 1;
				else
				{
					sta.top() += 2 * t;
				}
			}
		}

		return sta.top();
	}
};








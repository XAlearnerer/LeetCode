#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
	int largestRectangleArea2(vector<int>& heights) {
		stack<int> s;
		int res = 0, cur = 0;
		int i = 0;
		//for (int i = 0; i != heights.size(); ++i)
		while (i < heights.size())
		{
			if (s.empty() || heights[s.top()] <= heights[i])
			{
				s.push(i);
				++i;
			}
			else
			{
				int t = s.top();
				s.pop();
				cur = heights[t] * (s.empty() ? i : i - s.top() - 1);
				if (cur > res)
					res = cur;
			}
		}

		while (!s.empty())
		{
			int t = s.top();
			s.pop();
			cur = heights[t] * (s.empty() ? i : i - s.top() - 1);
			if (cur > res)
				res = cur;
		}
		return res;
	}
};


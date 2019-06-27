#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> t;
		int i = 0;
		int lararea = 0;
		while (i < heights.size())
		{
			if (t.empty() || heights[i] >= heights[t.top()])
			{
				t.push(i);
				++i;
			}
			else
			{
				int p = t.top();
				t.pop();
				int cur = 0;
				if (t.empty()) cur = heights[p] * i;
				else cur = heights[p] * (i - t.top() - 1);
				lararea = max(lararea, cur);
			}
		}

		while (!t.empty())
		{
			int p = t.top();
			t.pop();
			int cur = 0;
			if (t.empty()) cur = heights[p] * i;
			else cur = heights[p] * (i - t.top() - 1);
			lararea = max(lararea, cur);
		}

		return lararea;
	}
};



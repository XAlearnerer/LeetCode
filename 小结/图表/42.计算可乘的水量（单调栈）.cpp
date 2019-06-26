#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


// µ¥µ÷Õ»

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.empty()) return 0;
		stack<int> t;
		int i = 0, res = 0;
		while (i < height.size())
		{
			if (t.empty() || height[t.top()] >= height[i])
			{
				t.push(i); ++i;
				continue;
			}

			int p = t.top();
			t.pop();
			if (t.empty()) continue;
			res += ((min(height[i], height[t.top()]) - height[p]) * (i - 1 - t.top()));
		}

		return res;
	}
};

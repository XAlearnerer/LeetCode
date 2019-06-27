//
// Created by zhao on 18-11-9.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution2 {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.size() == 1) return heights[0];
		int maxarea = 0;
		int curarea = 0;
		vector<int> min(heights.size(), -1);
		for (int i = 0; i != heights.size(); ++i)
		{
			//if( maxarea/heights[i] >= (heights.size() - i) && heights[i] != 0 )
			if (heights[i] != 0 && maxarea / heights[i] >= (heights.size() - i))
				continue;
			for (int j = i; j != heights.size(); ++j)
			{
				if (i == j) min[j] = heights[j];
				else
				{
					if (heights[j] < min[j - 1]) {
						min[j] = heights[j];
					}
					else min[j] = min[j - 1];
				}
				curarea = min[j] * (j - i + 1);
				if (curarea > maxarea) {
					maxarea = curarea;
				}
			}
		}
		return maxarea;
	}
};



class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int top = 0;
		int maxarea = -1;
		stack<int> s;
		int curarea;

		int i = 0;
		while (i < heights.size())
		{
			if (s.empty() || heights[s.top()] <= heights[i])
				s.push(i++);

			else
			{
				top = s.top();
				s.pop();
				curarea = heights[top] * (s.empty() ? i : i - s.top() - 1);
				if (curarea > maxarea)
					maxarea = curarea;
			}
		}

		while (!s.empty())
		{
			top = s.top();
			s.pop();
			curarea = heights[top] * (s.empty() ? i : i - s.top() - 1);
			if (curarea > maxarea)
				maxarea = curarea;
		}

		return maxarea;
	}
};


//
//int main()
//{
//	vector<int> v={2,1,4,5,6,2};
//	Solution n;
//	cout << n.largestRectangleArea(v) << endl;
//
//	return 0;
//}
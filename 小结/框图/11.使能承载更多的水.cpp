#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;


class Solution {
public:
	int maxArea(vector<int>& height) {
		int  l = 0, r = height.size() - 1;
		int res = 0;
		while (l < r)
		{
			int cur = min(height[l], height[r])*(r - l);
			res = max(res, cur);
			//++l;

			if (height[l] < height[r]) ++l;
			else --r;

		}
		return res;
	}
};


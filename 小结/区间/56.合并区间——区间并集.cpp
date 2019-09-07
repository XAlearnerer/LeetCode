#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.empty()) return {};
		sort(intervals.begin(), intervals.end());
		vector<vector<int> > res;
		res.push_back(intervals[0]);

		for (int i = 1; i < intervals.size(); ++i)
		{
			if (res.back()[1] >= intervals[i][0])
				// 若不写 >= ，则 会出现 [1,4],[4,5] 这种情况
			{
				res.back()[1] = max(intervals[i][1], res.back()[1]);
			}
			else
			{
				res.push_back(intervals[i]);
			}
		}
		return res;
	}
};


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.empty() || intervals.size() == 1) return intervals;
		sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) 
		{	
			if (a[0] == b[0]) return a[1] < b[1];
			else return a[0] < b[0]; 
		});

		vector<vector<int> > res;
		res.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); ++i)
		{
			//if(res.back()[0]<= intervals[i][0] && res.back()[1] < intervals[i][1])
			if (res.back()[1] < intervals[i][0]) res.push_back(intervals[i]);
			else
			{
				if (res.back()[1] < intervals[i][1])
					res.back()[1] = intervals[i][1];
			}
		}

		return res;
	}
};
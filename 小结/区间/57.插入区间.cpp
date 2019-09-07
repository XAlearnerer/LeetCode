
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
   
// Input: [[1, 3], [2, 6], [8, 10], [15, 18]]
// Output : [[1, 6], [8, 10], [15, 18]]


//我们可以对给定的区间集进行一个一个的遍历比较，
//那么会有两种情况，重叠或是不重叠，不重叠的情况最好，
//直接将新区间插入到对应的位置即可，重叠的情况比较复杂，
//有时候会有多个重叠，我们需要更新新区间的范围以便包含所有重叠，
//之后将新区间加入结果 res，最后将后面的区间再加入结果 res 即可。


class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> res;
		int n = intervals.size();
		int pos = 0;
		while (pos < n && intervals[pos][1] < newInterval[0])
		{
			res.push_back(intervals[pos]);
			++pos;
		}

		while (pos < n && intervals[pos][0] <= newInterval[1])
		{
			newInterval[0] = min(newInterval[0], intervals[pos][0]);
			newInterval[1] = max(newInterval[1], intervals[pos][1]);
			++pos;
		}
		res.push_back(newInterval);

		while (pos < n)
		{
			res.push_back(intervals[pos]);
			++pos;
		}

		return res;
	}
};




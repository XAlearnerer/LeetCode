//
// Created by zhao on 18-12-3.
//

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//Output: [[1,2],[3,10],[12,16]]
//Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int i=0,len=intervals.size();
        while(i<len && newInterval.start>intervals[i].end)
            res.push_back(intervals[i++]);

        while (i < len && intervals[i].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            ++i;
        }
        res.push_back(newInterval);

        while(i<len)
            res.push_back(intervals[i++]);

        return res;
    }
};
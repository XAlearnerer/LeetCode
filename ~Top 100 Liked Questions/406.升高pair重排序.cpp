#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), [](vector<int> a, vector<int> b)
		{ if (a[0] == b[0]) return a[1] < b[1]; else return a[0] > b[0]; });

		vector<vector<int> > res;
		for (auto i : people)
		{
			res.insert(res.begin() + i[1], i);
		}
		return res;
	}
};






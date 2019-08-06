#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		if (buildings.empty()) return {};
		vector<vector<int>> res, h;
		multiset<int> t;
		t.insert(0);
		int pre = 0, cur = 0;
		for (auto i : buildings)
		{
			h.push_back({ i[1], i[2] });
			h.push_back({ i[0], -1 * i[2] });
		}

		sort(h.begin(), h.end());
		for (auto &a : h)
		{
			if (a[1] < 0) t.insert(-1 * a[1]);
			else t.erase(t.find(a[1]));

			cur = *t.rbegin();
			if (cur != pre)
			{
				res.push_back({ a[0],cur });
				pre = cur;
			}

		}
		return res;
	}
};


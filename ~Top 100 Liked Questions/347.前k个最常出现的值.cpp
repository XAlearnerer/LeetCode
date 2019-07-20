#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> m;
		for (auto i : nums)
			++m[i];
		priority_queue<pair<int,int>> q;
		for (auto i : m)
			q.push({ i.second,i.first });
		vector<int> res;
		for (int i = 0; i < k; ++i)
		{
			auto t = q.top();
			q.pop();
			res.push_back(t.second);
		}
		return res;
	}
};


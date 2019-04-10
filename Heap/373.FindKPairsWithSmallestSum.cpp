#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> res;
		for (int i = 0; i < min((int)nums1.size(), k); ++i)
		{
			for(int j = 0; j < min((int)nums2.size(), k); ++j)
			{
				res.push_back({ nums1[i],nums2[j] });
			}
		}

		sort(res.begin(), res.end(), [](pair<int, int>& a, pair<int, int>& b) 
			{return a.first + a.second < b.first + b.second; });

		if (res.size() > k) res.erase(res.begin() + k, res.end());
		return res;
	}
};
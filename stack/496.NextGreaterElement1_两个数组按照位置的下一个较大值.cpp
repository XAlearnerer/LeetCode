#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		for (int i = 0; i != nums1.size(); ++i)
		{
			auto it = find(nums2.begin(), nums2.end(), nums1[i]);
			int cur = *it;
			int prelen = res.size();
			while (it < nums2.end())
			{
				if (*it > cur)
				{
					res.push_back(*it);
					break;
				}
				++it;
			}
			if (res.size() == prelen) res.push_back(-1);
		}

		return res;
	}
};


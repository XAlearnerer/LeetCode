#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<map>
#include <queue>

using namespace std;

class Solution2 {
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

class Solution3 {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	    multimap<int,pair<int,int>> m;
	    vector<pair<int,int>> res;


        for (int i = 0; i < min((int)nums1.size(), k); ++i)
        {
            for (int j = 0; j < min((int)nums2.size(), k); ++j)
            {
                m.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second);
            if (--k <= 0) return res;
        }
        return res;
	}
};


class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>> ,cmp> q;
        vector<pair<int,int>> res;

        for (int i = 0; i < min((int)nums1.size(), k); ++i) {
            for (int j = 0; j < min((int)nums2.size(), k); ++j) {
                if (q.size() < k) {
                    q.push({nums1[i], nums2[j]});
                } else if (nums1[i] + nums2[j] < q.top().first + q.top().second) {
                    q.push({nums1[i], nums2[j]}); q.pop();
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.top()); q.pop();
        }
        return res;



    }

    struct cmp
    {
        bool operator() (pair<int,int> &a,pair<int,int> &b)
        {
            return a.first+a.second<b.first+b.second;
        }
    };
};
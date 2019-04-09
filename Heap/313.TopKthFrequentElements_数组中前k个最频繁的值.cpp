#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>

using namespace std;


class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		unordered_map<int, int> m;

		for (int i = 0; i != nums.size(); ++i)
		{
			if (m.count(nums[i]) == 0)
			{
				m.insert({ nums[i],1 });
			}
			else
			{
				++m[nums[i]];
			}
		}

		sort(m.begin(), m.end(), [](pair<int, int> a, pair<int, int> b) {return a.second > b.second; });
		vector<int> res;
		for (auto i:m)
		{
			res.push_back(i.first);
		}
		return res;
	}
};

class Solution {
public:
	// Time complexity O(n/g log(k)) where g is measure of average size of group.
	vector<int> topKFrequent(vector<int>& nums, int k) {
		// create cnt.
		unordered_map<int, int> cnt;
		set<pair<int, int>> s;
		for (auto x : nums) cnt[x]++; // O(n)
									  // create a balanced search tree structure of size k.
									  // adding new item should remove the lowest item, or not enter the tree.
		for (auto x : cnt) { // O(n/g)
			auto val = x.first;
			auto am = x.second;
			if (s.size() < k) { s.insert({ am, val }); } // O(log k)
			else {
				auto it = s.begin(); // smallest item
				if ((*it).first < am) {
					s.erase((*it)); // O(1)
					s.insert({ am, val }); // O(log k)
				}
			}
		}
		nums.clear();
		for (auto x : s) { // O(k)
			nums.push_back(x.second);
		}
		return nums;
	}
};
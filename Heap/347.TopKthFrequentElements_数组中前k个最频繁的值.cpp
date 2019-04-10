#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<queue>

using namespace std;

class Solution3 {
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
		//sort(m.begin(), m.end(), [](pair<int, int> a, pair<int, int> b) {return a.second > b.second; });

		multiset<pair<int, int>> s;
		for (auto a : m)
		{
			int val = a.first;
			int fre = a.second;

			s.insert({ fre,val });
		}

		cout << s.size() << endl;
		//for(auto q:s)
		//   cout<<q.first<<" -- "<<q.second<<endl;

		vector<int> res;
		auto iter = s.rbegin();
		for (int i = 0; i != k; ++i)
		{
			res.push_back(iter->second);
			++iter;
		}
		return res;
	}
};



class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> res;
		unordered_map<int, int> m;
		for (auto i : nums)
		{
			++m[i];
		}
		
		priority_queue<pair<int, int>>p;
		for (auto i : m)
		{
			p.push({ i.second,i.first });
		}

		for (int i = 0; i != k; ++i)
		{
			res.push_back(p.top().second);
			p.pop();
		}
		return res;
	}
};



class Solution2 {
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
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string> > m;
		for (auto i : strs)
		{
			string cur = helper(i);
			if (m.count(cur) == 0)
			{
				m.insert({ cur,{i} });
			}
			else m[cur].push_back(i);
		}

		vector<vector<string>> res;
		for (auto i : m)
		{
			res.push_back(i.second);
		}
		return res;
	}

	string helper(string s)
	{
		string ret(26, '0');
		for (auto i : s)
		{
			++ret[i - 'a'];
		}
		return ret;
	}

};
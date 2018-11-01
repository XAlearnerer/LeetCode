#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<string>

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		vector<string> ss;
		vector<vector<int>> v;
		for (int i = 0; i != strs.size(); ++i)
		{
			string s = strs[i];
			sort(s.begin(), s.end());
			auto it = find(ss.begin(), ss.end(), s);
			if ( it == ss.end())
			{
				ss.push_back(s);
				v.resize(ss.size());
				v[ss.size() - 1].push_back(i);
			}
			else
			{
				v[it-ss.begin()].push_back(i);
			}
		}
		for (int i = 0; i != v.size(); ++i)
		{
			vector<string> group;
			for (int j = 0; j != v[i].size(); ++j)
			{
				group.push_back(strs[v[i][j]]);
			}
			res.push_back(group);
		}

		return res;

	}
};


class Solution2 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		unordered_map<string, vector<string>> map;
		for (auto str : strs)
		{
			map[transfer(str)].push_back(str);
		}
	
		for (auto array : map)
		{
			ans.push_back(array.second);
		}
		return ans;
	}

	string transfer(string& s)
	{
		string ans(26, '0');
		for (int i = 0; i < s.size(); i++)
		{
			ans[s[i] - 'a']++;
		}
		return ans;
	}
};

int main2025()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution2 n;
	vector<vector<string>> vv = n.groupAnagrams(strs);
	for (auto i : vv) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}


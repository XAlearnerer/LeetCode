#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		unordered_map<int, unordered_set<int>> m;
		for (auto i : edges)
		{
			if (helper(i[0], i[1], m, -1)) return i;
			m[i[0]].insert(i[1]);
			m[i[1]].insert(i[0]);
		}
		return {};
	}

	bool helper(int cur,int tar, unordered_map<int, unordered_set<int>>& m,int pre)
	{
		if (m[cur].count(tar)) return true;
		for (auto i : m[cur])
		{
			if (i == pre) continue;
			if (helper(i, tar, m, cur)) return true;
		}

		return false;
	}

};





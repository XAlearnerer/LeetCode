#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		if (!root) return {};
		vector<int> res;
		vector<pair<int, int>> p;

		helper(root);

		for (auto i : m)
			p.push_back(i);
		sort(p.begin(), p.end(), [](pair<int, int>a, pair<int, int>b) {return a.second > b.second; });
		int maxnum = p[0].second;
		for (auto i : p)
		{
			if (i.second == maxnum)
				res.push_back(i.first);
			else
				break;
		}
		return res;
	}

	void helper(TreeNode* cur)
	{
		if (!cur) return;
		if (m.count(cur->val) == 0) m[cur->val] = 0;
		else ++m[cur->val];
		helper(cur->left);
		helper(cur->right);
	}

	unordered_map<int, int> m;
};



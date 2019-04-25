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
	vector<int> findFrequentTreeSum(TreeNode* root) {
		if (!root) return{};
		helper(root);

		vector<pair<int, int>> p;
		for (auto i : m)
			p.push_back(i);
		sort(p.begin(), p.end(), [](pair<int, int>a, pair<int, int>b) {return a.second > b.second; });

		vector<int> res;
		for (auto i : p)
		{
			if (i.second == p[0].second)
				res.push_back(i.first);
		}
		return res;

	}

	int helper(TreeNode* cur)
	{
		if (!cur) return 0;
		int thisnodesum = helper(cur->left) + helper(cur->right) + cur->val;
		if (m.count(thisnodesum) == 0) m[thisnodesum] = 1;
		else ++m[thisnodesum];
		return thisnodesum;
	}

	unordered_map<int, int> m;
};


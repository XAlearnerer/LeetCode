#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution2 {  /////////// worng
public:
	int minDiffInBST(TreeNode* root) {
		int m = INT_MAX;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* t = q.front();
			q.pop();
			if (t->left)
			{
				m = min(m, t->val - t->left->val);
				q.push(t->left);
			}
			if (t->right)
			{
				m = min(m, t->right->val - t->val);
				q.push(t->right);
			}
		}

		return m;
	}
};



class Solution {
public:
	int minDiffInBST(TreeNode* root) {
		vector<int> v;
		helper(root, v);
		int res = INT_MAX;
		for (int i = 0; i != v.size() - 1; ++i)
			res = min(res, v[i + 1] - v[i]);
		return res;
	}

	void helper(TreeNode* root, vector<int>& v)
	{
		if (!root) return;
		helper(root->left, v);
		v.push_back(root->val);
		helper(root->right, v);
	}

};
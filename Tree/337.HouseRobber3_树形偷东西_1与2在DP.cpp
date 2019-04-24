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


class Solution2 {
public:
	int rob(TreeNode* root) {
		if (!root) return 0;
		return helper(root);
	}

	int helper(TreeNode* cur)
	{
		if (!cur) return 0;
		if (m.count(cur) != 0) return m[cur];
		int val = 0;
		if (cur->left) val += helper(cur->left->left) + helper(cur->left->right);
		if (cur->right) val += helper(cur->right->left) + helper(cur->right->right);
		int maxval = max(helper(cur->left) + helper(cur->right), val + cur->val);
		m[cur] = maxval;
		return maxval;
	}

	unordered_map<TreeNode*, int> m;
};



class Solution {
public:
	int rob(TreeNode* root) {
		int l = 0, r = 0;
		return helper(root, l, r);
	}

	int helper(TreeNode* cur,int& l,int& r)
	{
		if (!cur) return 0;
		int ll = 0, lr = 0, rl = 0, rr = 0;
		l = helper(cur->left, ll, lr);
		r = helper(cur->right, rl, rr);
		return max(cur->val + ll + lr + rl + rr, l + r);
	}

};
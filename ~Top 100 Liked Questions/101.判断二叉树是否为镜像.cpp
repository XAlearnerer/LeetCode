
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return helper(root->left, root->right);
	}

	bool helper(TreeNode* l, TreeNode* r)
	{
		if (!l && !r) return true;
		if ((!r && l) || (!l&& r) || (l->val != r->val)) return false;
		return helper(l->left, r->right) && helper(l->right, r->left);
	}
};
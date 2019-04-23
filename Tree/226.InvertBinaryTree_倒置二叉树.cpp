#include<iostream>
#include<algorithm>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution2 {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root) return root;
		helper(root);
		return root;
	}

	void helper(TreeNode* cur)
	{
		if (cur->left && cur->right)
		{
			swap(cur->left->val, cur->right->val);
			helper(cur->left);
			helper(cur->right);
		}
		else if (!cur->left && !cur->right)
			return;
		else if (cur->left)
		{
			cur->right = cur->left;
			cur->left = NULL;
			helper(cur->right);
		}
		else
		{
			cur->left = cur->right;
			cur->right = NULL;
			helper(cur->left);
		}
	}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return root;
		TreeNode* tmp = root->left;

		root->left = invertTree(root->right);
		root->right = invertTree(tmp);
		return root;

	}
};

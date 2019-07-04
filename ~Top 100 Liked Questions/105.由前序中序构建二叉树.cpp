#include<vector>
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty()) return NULL;
		if (inorder.empty()) return NULL;
		return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode* helper(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir)
	{
		if (pl > pr || il > ir) return NULL;
		int pos = -1;
		for (pos = il; pos <= ir; ++pos)
		{
			if (inorder[pos] == preorder[pl]) break;
		}
		TreeNode* root = new TreeNode(preorder[pl]);
		root->left = helper(preorder, pl + 1, pl + pos - il, inorder, il, pos - 1);
		root->right = helper(preorder, pl + pos - il + 1, pr, inorder, pos + 1, ir);
		return root;
	}
};
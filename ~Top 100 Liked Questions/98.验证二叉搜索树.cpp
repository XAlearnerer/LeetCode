
#include<iostream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution_OWE {
public:
	bool isValidBST(TreeNode* root) {
		return helper(root, INT_MIN, INT_MAX);
	}

	bool helper(TreeNode* root,int l,int r)
	{
		if (!root) return true;
		if (root->val >= r || root->val <= l) return false;
		else
			return helper(root->left, l, root->val) && helper(root->right, root->val, r);
	}

};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return helper(root, LONG_MIN, LONG_MAX);
	}

	bool helper(TreeNode* root, long l, long r)
	{
		if (!root) return true;
		if (root->val >= r || root->val <= l) return false;
		else
			return helper(root->left, l, root->val) && helper(root->right, root->val, r);
	}

};
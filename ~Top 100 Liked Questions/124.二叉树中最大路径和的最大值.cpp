#include<iostream>
#include<algorithm>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
	int maxPathSum(TreeNode* root) {
		if (!root) return 0;
		//int res = 0;
		int res = INT_MIN;
		helper(root, res);
		return res;
	}

	int helper(TreeNode* root, int& res)
	{
		if (!root) return 0;
		int l = max(helper(root->left, res), 0);
		int r = max(helper(root->right, res), 0);
		res = max(res, l + r + root->val);

		return max(l, r) + root->val;
	}

};



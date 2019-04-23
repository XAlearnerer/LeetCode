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
	int countNodes(TreeNode* root) {
		if (!root) return 0;
		return helper(root);
	}

	int helper(TreeNode* cur)
	{
		if (!cur->left && !cur->right)
			return 1;
		if (cur->left && cur->right)
			return helper(cur->left) + helper(cur->right) + 1;
		if (cur->left)
			return helper(cur->left) + 1;
		else
			return helper(cur->right) + 1;
	}

};



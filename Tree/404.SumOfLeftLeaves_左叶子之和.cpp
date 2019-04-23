#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root) return 0;
		int sum = 0;
		helper(root, sum);
		return sum;
	}

	void helper(TreeNode* root ,int &sum)
	{
		if (root->left)
		{
			sum += root->left->val;
			helper(root->left, sum);
		}
		if (root->right)
			helper(root->right, sum);
	}

};

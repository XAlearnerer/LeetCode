#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<queue>
#include<string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (!root) return NULL;
		if (root->val < L)
		{
			return trimBST(root->right, L, R);
		}
		if (root->val > R)
		{
			return trimBST(root->left, L, R);
		}

		if (root->left) root->left = trimBST(root->left, L, R);
		if (root->right) root->right = trimBST(root->right, L, R);
		return root;
	}
};
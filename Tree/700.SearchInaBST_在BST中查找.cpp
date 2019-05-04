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
	TreeNode* searchBST(TreeNode* root, int val) {
		if (!root) return NULL;
		if (val == root->val) return root;
		else if (val > root->val) return searchBST(root->right, val);
		else return searchBST(root->left, val);
	}
};


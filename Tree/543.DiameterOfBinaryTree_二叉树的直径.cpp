#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		int res = 0;
		if (!root) return NULL;
		helper(root, res);
		return res;

	}
	int helper(TreeNode* cur, int& dia)
	{
		if (!cur) return 0;
		int l = helper(cur->left, dia);
		int r = helper(cur->right, dia);
		dia = max(dia, l + r);
		return 1 + max(l, r);
	}
};


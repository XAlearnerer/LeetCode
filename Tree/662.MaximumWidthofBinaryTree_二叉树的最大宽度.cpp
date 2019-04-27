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
	int widthOfBinaryTree(TreeNode* root) {
		int res = 0;
		vector<int> start;
		helper(root, 0, 1, start, res);
		return res;
	}

	void helper(TreeNode* node, int h, int index, vector<int>& start, int& res) {
		if (!node) return;
		if (h >= start.size()) start.push_back(index);
		res = max(res, index - start[h] + 1);
		helper(node->left, h + 1, index * 2, start, res);
		helper(node->right, h + 1, index * 2 + 1, start, res);
	}
};





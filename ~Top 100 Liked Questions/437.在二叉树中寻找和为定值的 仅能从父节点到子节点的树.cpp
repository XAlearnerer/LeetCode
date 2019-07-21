#include<iostream>
#include<vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution1 {
public:
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		vector<int> v;
		int res = 0;
		helper(root, sum, v, res, 0);
		return res;
	}

	void helper(TreeNode* root, int sum, vector<int>& out, int& res,int cur)
	{
		if (!root) return;
		out.push_back(root->val);
		cur += root->val;
		if (sum == cur) ++res;
		
		int tmp = cur;
		for (int i = 0; i < out.size() - 1; ++i)
		{
			tmp -= out[i];
			if (tmp == sum) ++res;
		}
		
		helper(root->left, sum, out, res, cur);
		helper(root->right, sum, out, res, cur);

		out.pop_back();
	}

};



class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		return helper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}

	int helper(TreeNode* root, int pre, int sum)
	{
		if (!root) return 0;
		pre += root->val;
		int p;
		if (pre == sum) p = 1;
		else p = 0;
		return helper(root->right, pre, sum) + helper(root->left, pre, sum) + p;
	}
};

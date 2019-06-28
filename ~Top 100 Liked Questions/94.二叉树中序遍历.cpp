#include<iostream>
#include<vector>
#include<stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution2 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root) return {};
		vector<int> res;
		helper(root, res);
		return res;
	}

	void helper(TreeNode* root, vector<int>& res)
	{
		if (!root) return;
		helper(root->left, res);
		res.push_back(root->val);
		helper(root->right, res);
	}

};



class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root) return {};
		stack<TreeNode*> t;
		vector<int> res;

		while (1)
		{
			if (root)
			{
				t.push(root);
				root = root->left;
			}
			else if (!t.empty())
			{
				root = t.top();
				t.pop();
				res.push_back(root->val);
				root = root->right;
			}
			else break;
		}

		
		return res;
	}
};

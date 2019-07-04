#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) :val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root) return {};
		queue<TreeNode*> q;
		q.push(root);
		vector<vector<int>> res;
		while (!q.empty())
		{
			int len = q.size();
			vector<int> t;
			for (int i = 0; i < len; ++i)
			{
				TreeNode* a = q.front();
				q.pop();
				t.push_back(a->val);
				if (a->left) q.push(a->left);
				if (a->right) q.push(a->right);
			}
			res.push_back(t);
		}
		return res;
	}
};



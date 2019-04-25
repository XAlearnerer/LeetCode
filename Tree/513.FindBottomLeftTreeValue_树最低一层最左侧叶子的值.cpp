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
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> q;
		if (!root) return 0;
		int res = -1;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i != size; ++i)
			{
				TreeNode* t = q.front();
				q.pop();
				if (i == 0) res = t->val;
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
		}
		return res;
	}
};


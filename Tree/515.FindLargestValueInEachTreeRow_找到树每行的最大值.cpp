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
	vector<int> largestValues(TreeNode* root) {
		queue<TreeNode*> q;
		if (!root) return {};
		vector<int> res;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			int m = INT_MIN;
			for (int i = 0; i != size; ++i)
			{
				TreeNode* t = q.front();
				q.pop();
				if (t->val > m) m = t->val;
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			res.push_back(m);
		}
		return res;
	}
};



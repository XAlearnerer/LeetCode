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
	vector<double> averageOfLevels(TreeNode* root) {
		if (!root) return {};
		queue<TreeNode*> q;
		q.push(root);
		vector<double> res;
		while (!q.empty())
		{
			int len = q.size();
			double m = 0;
			for (int i = 0; i != len; ++i)
			{
				TreeNode* t = q.front();
				q.pop();
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
				m += t->val;
			}
			res.push_back(m / len);
		}
		return res;
	}
};
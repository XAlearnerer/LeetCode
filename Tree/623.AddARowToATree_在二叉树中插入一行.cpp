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
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (!root) return NULL;
		if (d == 1)
		{
			TreeNode* be = new TreeNode(v);
			be->left = root;
			return be;
		}

		TreeNode* be = root;
		queue<TreeNode*> q;
		q.push(root);
		int level = 1;
		while (!q.empty())
		{
			if (level < d - 1)
			{
				int sz = q.size();
				for (int i = 0; i != sz; ++i)
				{
					TreeNode* t = q.front();
					q.pop();
					if (t->left) q.push(t->left);
					if (t->right) q.push(t->right);
				}
				++level;
			}
			else
			{
				int sz = q.size();
				for (int i = 0; i != sz; ++i)
				{
					TreeNode* t = q.front();
					q.pop();
					TreeNode* curl = curl = t->left, *curr = curr = t->right;
					TreeNode* newl = new TreeNode(v);
					TreeNode* newr = new TreeNode(v);

					newl->left = curl;
					newl->right = NULL;

					newr->left = NULL;
					newr->right = curr;

					t->left = newl;
					t->right = newr;
				}
				break;
			}
		}

		return be;
	}
};


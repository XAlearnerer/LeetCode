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
	bool findTarget(TreeNode* root, int k) {
		if (!root) return false;
		unordered_set<int> s;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode* cur = q.front();
			q.pop();
			if (s.count(cur->val) > 0) return true;
			s.insert(k - cur->val);
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}

		return false;
	}
};


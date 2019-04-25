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
	TreeNode* convertBST(TreeNode* root) {
		if (!root) return NULL;
		queue<TreeNode*> q;
		q.push(root);
		int sum = 0;
		while (!q.empty())
		{
			TreeNode* t = q.front();
			q.pop();
			sum += t->val;
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);
		}

		TreeNode* be = root;
		helper(root, sum);
		return be;

	}

	void helper(TreeNode* cur, int& sum)
	{
		if (!cur) return;
		if (!cur) return;
		helper(cur->left, sum);
		sum -= cur->val;
		cur->val = sum + cur->val;
		helper(cur->right, sum);
	}



};














//我开始想的方法是先求出所有结点值之和，然后开始中序遍历数组，
//同时用变量sum来记录累加和，根据上面分析的规律来更新所有的数组。
//但是通过看论坛，发现还有更巧妙的方法，不用先求出的所有的结点值之和，
//而是巧妙的将中序遍历左根右的顺序逆过来，变成右根左的顺序，
//这样就可以反向计算累加和sum，同时更新结点值，叼的不行
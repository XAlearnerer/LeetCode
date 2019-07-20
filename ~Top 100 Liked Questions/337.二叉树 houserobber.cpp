#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


 //!  并不是 一定间隔一行
 
 //!      4
 //!       1
 //!        2
 //!         3
 
 //! 最大值为 4+3 =7 而不是 max（6，4）


//class Solution {
//public:
//	int rob(TreeNode* root) {
//		if (!root) return 0;
//		if (!root->left && !root->right) return root->val;
//		queue<TreeNode*> q;
//		q.push(root);
//		int odd = 0, even = 0;
//		int level = 1;
//		while (!q.empty())
//		{
//			int size = q.size();
//			int cur = 0;
//			for (int i = 0; i < size; ++i)
//			{
//				TreeNode* t = q.front();
//				q.pop();
//				cur += t->val;
//				if (t->left) q.push(t->left);
//				if (t->right)q.push(t->right);
//			}
//			if (level % 2 == 1) odd += cur;
//			else even += cur;
//			++level;
//		}
//
//		if (odd > even) return odd;
//		else return even;
//	}
//};



class Solution {
public:
	int rob(TreeNode* root) {
		if (!root) return 0;
		int l = 0, r = 0;
		return helper(root, l, r);
	}

	int helper(TreeNode* root,int& l,int& r)
	{
		if (!root) return 0;
		int ll = 0, lr = 0, rl = 0, rr = 0;
		l = helper(root->left, ll, lr);
		r = helper(root->right, rl, rr);

		return max(l + r, ll + lr + rl + rr + root->val);
	}

};



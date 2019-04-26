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

class Solution2 {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s) return false;
		if (sametree(s, t)) return true;
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}

	bool sametree(TreeNode* s, TreeNode* t)
	{
		if (!s && !t) return true;
		if (!s || !t) return false;
		if (s->val != t->val) return false;
		return sametree(s->left, t->left) && sametree(s->right, t->right);
	}
};

//class Solution {
//public:
//	bool isSubtree(TreeNode* s, TreeNode* t) {
//		vector<int> res, res2;
//		helper(s, res);
//		helper(t, res2);
//
//		if (search(res.begin(), res.end(), res2.begin(), res2.end()) == res.end()) return false;
//		else return true;
//	}
//
//	void helper(TreeNode* root, vector<int>& res)
//	{
//		if (!root) return;
//		helper(root->left, res);
//		helper(root->right, res);
//		res.push_back(root->val);
//	}
//};
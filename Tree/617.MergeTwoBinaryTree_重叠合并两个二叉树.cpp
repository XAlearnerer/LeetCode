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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t1) return t2;
		if (!t2) return t1;

		TreeNode* t = new TreeNode(t1->val + t2->val);
		t->left = mergeTrees(t1->left, t2->left);
		t->right = mergeTrees(t1->right, t2->right);
		return t;

	}
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t1) return t2;
		if (!t2) return t1;

		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;

	}
};

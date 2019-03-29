//Definition for a binary tree node.

#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//class Solution {
//public:
//	vector<string> binaryTreePaths(TreeNode* root) {
//		stack<TreeNode*> s;
//		string str = "";
//		vector<string> vs;
//		s.push(root); 
//		while (!s.empty())
//		{
//			TreeNode* t = s.top();
//			s.pop();
//			if (t->left == NULL && t->right == NULL)
//			{
//				str = str + to_string(t->val);
//				vs.push_back(str);
//				continue;
//			}
//
//			if (t->left != NULL && t->right != NULL)
//			{
//				str = str + to_string(t->val) + "->";
//				s.push(t->left);
//				s.push(t->right);
//				continue;
//			}
//			
//			if (t->left != NULL)
//			{
//				str = str + to_string(t->val) + "->";
//				s.push(t->left);
//			}
//			if (t->right != NULL)
//			{
//				str = str + to_string(t->val) + "->";
//				s.push(t->right);
//			}
//		}
//
//		return vs;
//	}
//};
//


class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (root) helper(root, "", res);
		return res;
	}
	void helper(TreeNode* node, string out, vector<string>& res) {
		if (!node->left && !node->right) res.push_back(out + to_string(node->val));
		if (node->left) helper(node->left, out + to_string(node->val) + "->", res);
		if (node->right) helper(node->right, out + to_string(node->val) + "->", res);
	}
};

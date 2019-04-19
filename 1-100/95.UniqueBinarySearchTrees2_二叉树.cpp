//
// Created by zhao on 18-11-22.
//

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution2 {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return {};
		return helper(1, n);
	}

	vector<TreeNode*> helper(int left, int right)
	{
		vector<TreeNode*> tree;
		if (left > right)
		{
			tree.push_back(NULL);
		}

		for (int i = left; i <= right; ++i) {
			vector<TreeNode *> leftTree = helper(left, i - 1);
			vector<TreeNode *> rightTree = helper(i + 1, right);

			for (int j = 0; j != leftTree.size(); ++j)
				for (int k = 0; k != rightTree.size(); ++k)
				{
					TreeNode *nodei = new TreeNode(i);
					nodei->left = leftTree[j];
					nodei->right = rightTree[k];
					tree.push_back(nodei);
				}
		}
		return tree;
	}
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return {};
		vector<TreeNode*> *t = helper(1, n);
		return *t;
	}

	vector<TreeNode*> *helper(int left, int right)
	{
		vector<TreeNode*> *Tree = new vector<TreeNode*>();
		if (left > right)
			Tree->push_back(NULL);

		for (int i = left; i <= right; ++i)
		{
			vector<TreeNode*> *leftTree = helper(left, i - 1);
			vector<TreeNode*> *rightTree = helper(i + 1, right);
			for (int j = 0; j != leftTree->size(); ++j)
				for (int k = 0; k != rightTree->size(); ++k)
				{
					TreeNode *nodei = new TreeNode(i);
					nodei->left = (*leftTree)[j];
					nodei->right = (*rightTree)[k];
					Tree->push_back(nodei);
				}
		}

		return Tree;
	}
};
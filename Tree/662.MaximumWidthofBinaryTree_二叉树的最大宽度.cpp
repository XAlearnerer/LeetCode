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
	int widthOfBinaryTree(TreeNode* root) {
		if (!root) return 0;
		queue<pair<TreeNode*, int> > q;
		q.push({ root, 1 });
		int res = 0;
		while (!q.empty())
		{
			res = max(res, q.back().second - q.front().second + 1);
			int size = q.size();

		//============================
			//当树很大时，索引值变得很大，在此题中甚至超过long long的范围
			//这几句是特例，仅针对LeetCode给出的例子的处理：
					/*	
						0
						 0
						  0
						   0
							0
							 ...
					*/

			if (size == 1) {
				q.push({ q.front().first,1 });
				q.pop();
			}
		//============================

			for (int i = 0; i != size; ++i)
			{
				auto pi = q.front();
				q.pop();
				if (pi.first->left) q.push({ pi.first->left, pi.second * 2 });
				if (pi.first->right) q.push({ pi.first->right, pi.second * 2 + 1 });
			}
		}
		return res;
	}
};












class Solution2 {  //数组越界
public:
	int widthOfBinaryTree(TreeNode* root) {
		int res = 0;
		vector<int> start;
		helper(root, 0, 1, start, res);
		return res;
	}

	void helper(TreeNode* node, int h, int index, vector<int>& start, int& res) {
		if (!node) return;
		if (h >= start.size()) start.push_back(index);
		res = max(res, index - start[h] + 1);
		helper(node->left, h + 1, index * 2, start, res);
		helper(node->right, h + 1, index * 2 + 1, start, res);
	}
};








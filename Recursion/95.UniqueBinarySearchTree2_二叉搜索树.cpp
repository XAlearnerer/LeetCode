#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return {};
		return helper(1, n);
	}

	vector<TreeNode*> helper(int left, int right)
	{
		vector<TreeNode*> curv;
		if (left > right)
			return { NULL };
		//  return { nullptr }; Worng

		for (int i = left; i <= right; ++i)
		{
			vector<TreeNode*> lv = helper(left, i - 1);
			vector<TreeNode*> lr = helper(i + 1, right);
			for (int p = 0; p != lv.size(); ++p)
			{
				for (int q = 0; q != lr.size(); ++q)
				{
					TreeNode* cur = new TreeNode(i);
					cur->left = lv[p];
					cur->right = lr[q];
					curv.push_back(cur);
				}
			}
		}

		return curv;
	}

};

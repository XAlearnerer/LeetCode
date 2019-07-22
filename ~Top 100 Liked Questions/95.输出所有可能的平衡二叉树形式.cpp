#include<iostream>
#include<vector>

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
		if (n <= 0) return {};
		return helper(1, n);
	}

	vector<TreeNode*> helper(int l, int r)
	{
		vector<TreeNode*> res;
		if (l <= r)
		{
			for (int i = l; i <= r; ++i)
			{
				vector<TreeNode*> lT = helper(l, i - 1);
				vector<TreeNode*> rT = helper(i + 1, r);
				for (int j = 0; j < lT.size(); ++j)
				{
					for (int k = 0; k < rT.size(); ++k)
					{
						TreeNode* root = new TreeNode(i);
						root->left = lT[j];
						root->right = rT[k];
						res.push_back(root);
					}
				}
			}
		}
		else
			res.push_back(NULL);
		
		return res;
	}
};



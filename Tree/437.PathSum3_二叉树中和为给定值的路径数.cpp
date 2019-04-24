#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//class Solution {
//public:
//	int pathSum(TreeNode* root, int sum) {
//		if (!root) return 0;
//		int res = 0;
//		helper(root, sum, res);
//		return res;
//	}
//
//	int helper(TreeNode* cur, int sum, int& res)
//	{
//		if (!cur) return 0;
//		int val = cur->val;
//		if (cur->left) val += helper(cur->left, sum, res);
//		if (cur->right) val += helper(cur->right, sum, res);
//		if (sum == val) ++res;
//		return val;
//	}
//};


//中序  InorderTeaversal
class Solution2 {
public:
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		if (!root->left && !root->right) return root->val == sum ? 1 : 0;

		vector<TreeNode*> out;
		int res = 0;
		helper(root, out, sum, res, 0);
		return res;
	}

	void helper(TreeNode* cur, vector<TreeNode*>& out, int sum, int& res, int cursum)
	{
		if (!cur) return;
		out.push_back(cur);
		cursum += cur->val;
		if (cursum == sum) ++res;

		int t = cursum;
		for (int i = 0; i != out.size() - 1; ++i) 
			//for (int i = 0; i != out.size() ; ++i) 这样的话t值会减到0， 若sum==0， 则++res
		{
			t -= out[i]->val;
			if (t == sum) ++res;
		}

		helper(cur->left, out, sum, res, cursum);
		helper(cur->right, out, sum, res, cursum);

		out.pop_back();
	}
};




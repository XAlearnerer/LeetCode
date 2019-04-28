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





class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		if (!root) return 0;
		queue<pair<TreeNode*, int> > q;
		q.push({ root, 1 });
		int ans = 0;
		while (!q.empty()) {
			int size = q.size();
			if (size == 1) {
				q.push({ q.front().first,1 });
				q.pop();
			}
			ans = max(q.back().second - q.front().second + 1, ans);

			while (size-->0) {
				auto node = q.front().first;
				auto idx = q.front().second;
				q.pop();
				if (node->left)
					q.push({ node->left, idx * 2 });
				if (node->right)
					q.push({ node->right, idx * 2 + 1 });
			}

		}
		return ans;
	}
};


#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
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
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		if (!root) return{};
		vector<TreeNode*> res;
		unordered_map<string, int> m;
		helper(root, res, m);
		return res;
	}

	string helper(TreeNode* cur, vector<TreeNode*>& res, unordered_map<string, int>& m)
	{
		if (!cur) return "#";
		string s = to_string(cur->val) + "," + helper(cur->left, res, m) +
			"," + helper(cur->right, res, m);
		if (m[s] == 1) res.push_back(cur);
		++m[s];
		return s;
	}
};








//后来去网上看大神们的解法，发现果然是很叼啊，用到了前序遍历，
//还有数组序列化，并且建立序列化跟其出现次数的映射，
//这样如果我们得到某个结点的序列化字符串，而该字符串正好出现的次数为1，
//说明之前已经有一个重复树了，我们将当前结点存入结果res，
//这样保证了多个重复树只会存入一个结点，参见代码如下


class Solution2 {
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		vector<TreeNode*> res;
		unordered_map<string, int> m;
		helper(root, m, res);
		return res;
	}
	string helper(TreeNode* node, unordered_map<string, int>& m, vector<TreeNode*>& res) {
		if (!node) return "#";
		string str = to_string(node->val) + "," + helper(node->left, m, res) + "," + helper(node->right, m, res);
		if (m[str] == 1) res.push_back(node);
		++m[str];
		return str;
	}
};
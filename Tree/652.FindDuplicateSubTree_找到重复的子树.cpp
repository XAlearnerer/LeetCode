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








//����ȥ���Ͽ������ǵĽⷨ�����ֹ�Ȼ�Ǻܵ𰡣��õ���ǰ�������
//�����������л������ҽ������л�������ִ�����ӳ�䣬
//����������ǵõ�ĳ���������л��ַ����������ַ������ó��ֵĴ���Ϊ1��
//˵��֮ǰ�Ѿ���һ���ظ����ˣ����ǽ���ǰ��������res��
//������֤�˶���ظ���ֻ�����һ����㣬�μ���������


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
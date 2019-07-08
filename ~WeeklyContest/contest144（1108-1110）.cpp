#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <map>

using namespace std;

class Solution1108 {
public:
	string defangIPaddr(string address) {
		int len = address.size();
		int nlen = len + 6;
		int count = 0;
		string res;
		for (int i = len - 1; i >= 0; --i)
		{
			if (address[i] != '.') res.push_back(address[i]);
			else res.append("].[");
		}
		reverse(res.begin(), res.end());
		return res;

	}
};



////////////////////////////////////////////////////////////////////////////////////////


class Solution1109_worng {  //? 超时
public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		vector<int> res(n, 0);
		for (auto i : bookings)
		{
			for (int j = i[0]; j <= i[1]; ++j)
			{
				res[j - 1] += i[2];
			}
		}

		return res;
	}
};


class Solution1109 {
public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		vector<int> res(n, 0);
		for (auto i : bookings)
		{
			res[i[0] - 1] += i[2];
			if (i[1] < n)
				res[i[1]] -= i[2];
		}
		for (int i = 1; i < n; ++i)
		{
			res[i] += res[i - 1];
		}
		return res;
	}
};





////////////////////////////////////////////////////////////////////////////////////////



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//
//class Solution {
//public:
//	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
//		if (!root) return {};
//		unordered_set<int> t(to_delete.begin(), to_delete.end());
//
//		vector<TreeNode*> res;
//		TreeNode* dummy = new TreeNode(-1);
//		dummy->left = root;
//		dummy->right = NULL;
//		TreeNode* pre = dummy;
//
//		queue<pair<TreeNode*&, TreeNode*&>> q;
//		q.push({ dummy,root });
//		res.push_back(dummy);
//		while (!q.empty())
//		{
//			auto cur = q.front();
//			q.pop();
//
//			if (t.count(cur.second->val) != 0)
//			{
//				auto it = find(res.begin(), res.end(), cur.second->val);
//				if (it != res.end())
//				{
//					res.erase(it);
//				}
//				else
//				{
//					cur.first->left = NULL;
//					cur.second->right = NULL;
//				}
//				if (cur.second->left)
//					res.push_back(cur.second->left);
//				if (cur.second->right)
//					res.push_back(cur.second->right);
//			}
//			if (cur.second->left)
//				q.push({ cur.second,cur.second->left });
//			if (cur.second->right)
//				q.push({ cur.second,cur.second->right });
//		}
//
//		if (res[0]->left)
//		{
//			res.push_back(root);
//		}
//		res.erase(res.begin());
//
//		return res;
//	}
//};
//


class Solution1110 {
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		unordered_set<int> t(to_delete.begin(), to_delete.end());
		vector<TreeNode*> res;
		root = helper(root, t, res);
		if (root) res.push_back(root);
		return res;
	}

	TreeNode* helper(TreeNode* root, unordered_set<int> t, vector<TreeNode*>& res)
	{
		if (!root) return nullptr;

		/////////////////////////////////////////////

		root->left = helper(root->left, t, res);
		root->right = helper(root->right, t, res);

		/////////////////////////////////////////////

		if (t.count(root->val) != 0)
		{
			if (root->left) res.push_back(root->left);
			if (root->right) res.push_back(root->right);
			root = nullptr;
		}

		return root;

	}
};



////////////////////////////////////////////////////////////////////////////////////////




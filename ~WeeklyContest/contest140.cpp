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


class Solution1078 {
public:
	vector<string> findOcurrences(string text, string first, string second) {
		vector<string> res;
		vector<string> cur;
		int i = 0, j = 0;
		while (j < text.size())
		{
			string s;
			if (text[j] == ' ')
			{
				s = text.substr(i, j - i);
				i = j + 1;
				cur.push_back(s);
			}
			++j;
		}
		string s = text.substr(i, j - i);
		cur.push_back(s);

		//for (auto i : cur)
		//	cout << i << " ";
		//cout << endl;

		for (int i = 2; i < cur.size(); ++i)
		{
			if (cur[i - 2] == first && cur[i - 1] == second)
				res.push_back(cur[i]);
		}

		return res;
	}
};


///////////////////////////////////////////////////////////////////////////////////////

//class Solution1079 {
//public:
//	int numTilePossibilities(string tiles) {
//		if (tiles.empty()) return 0;
//		int n = tiles.size();
//		vector<int> v(26, 0);
//		for (auto i : tiles)
//			++v[i - 'A'];
//		int dif = 0;
//		for (int i = 0; i < v.size(); ++i)
//			if (v[i] != 0) ++dif;
//
//		int res = 0;
//		res += dif;
//
//
//
//	}
//};


class Solution1079 {
public:
	int numTilePossibilities(string tiles) {
		int res = 0;
		set<string> set;  //? 使用 set 消除重复值
		vector<int> v(tiles.size(), 0);
		helper(tiles, set, res, "", v);
		return res;
	}

	void helper(string& tiles, set<string>& set,int &res,string str,vector<int>& v)
	{
		if (str.size() != 0 && set.count(str) == 0)
		{
			++res;
			set.insert(str);
		}
	
		for (int i = 0; i < tiles.size(); ++i)   //? 这里实现 所有 排列
		{
			if (v[i] == 1) continue;
			v[i] = 1;
			helper(tiles, set, res, str+string(1, tiles[i]), v);
			v[i] = 0;
		}
	}
};


///////////////////////////////////////////////////////////////////////////////////////


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//	TreeNode* sufficientSubset(TreeNode* root, int limit) {
//		if (!root) return root;
//		if (root->val < limit) return NULL;
//		helper(root->left, limit, root->val, root, 0);
//		helper(root->right, limit, root->val, root, 1);
//		return root;
//	}
//
//	void helper(TreeNode*& root, int limit,int cur,TreeNode* pre,int lr)
//	{
//		if (!root) return;
//		if (cur + root->val >= limit)
//		{
//			if (root->left) helper(root->left, limit, cur + root->val, root, 0);
//			if (root->right) helper(root->right, limit, cur + root->val, root, 1);
//		}
//		else
//		{
//			if(lr==0)
//				pre->left = NULL;
//			if(lr==1)
//				pre->right = NULL;
//		}
//
//	
//	}
//};
//

//
//class Solution {
//public:
//	TreeNode* sufficientSubset(TreeNode* root, int limit) {
//		if (!root) return root;
//		helper(root, 0);
//		helper2(root->left, limit, root, 0);
//		helper2(root->right, limit, root, 1);
//		return root;
//	}
//
//	void helper(TreeNode* &root, int cur)
//	{
//		if (!root) return;
//		root->val += cur;
//		helper(root->left, cur + root->val);
//		helper(root->right, cur + root->val);
//	}
//
//	void helper2(TreeNode*& root, int limit, TreeNode* pre, int lr)
//	{
//		if (!root) return;
//		if (root->val >= limit)
//		{
//			if (root->left) helper2(root->left, limit, root, 0);
//			if (root->right) helper2(root->right, limit, root, 1);
//		}
//		else
//		{
//			if (lr == 0)
//				pre->left = NULL;
//			if (lr == 1)
//				pre->right = NULL;
//		}
//	}
//};


// emmmmmmmmmmmm,我在干什么？？？？？？？？？？？？

class Solution1080 {
public:
	TreeNode* sufficientSubset(TreeNode* root, int limit) {
		if (helper(root, limit, 0) < limit) return NULL;
		else
			return root;
	}

	int helper(TreeNode* &root, int limit, int pre)
	{
		if (!root) return pre;
		int l = helper(root->left, limit, pre + root->val);
		int r = helper(root->right, limit, pre + root->val);

		if (root->left && l < limit) root->left = NULL;
		if (root->right && r < limit) root->right = NULL;

		return max(l, r);

	}

};




///////////////////////////////////////////////////////////////////////////////////////



//class Solution1081 {
//public:
//	string smallestSubsequence(string text) {
//		if (!text.empty()) return "";
//		vector<int> v(26, 0);
//		for (auto i : text) ++v[i - 'a'];
//
//		vector<int> a(26, 0);
//		for (int i = 0; i < 26; ++i)
//			if (v[i] != 0) ++a[i];
//			 
//		string res;
//		int cur = 0;
//		for (int i = 0; i < text.size(); ++i)
//		{
//			--v[text[i] - 'a'];
//			--a[text[i] - 'a'];
//
//			if (a[text[i] - 'a' == 0])
//			{
//				res += text[i];
//			}
//			else
//			{
//				if (v[text[i] - 'a'] > 0)
//				{
//					auto it = find(res.begin(), res.end(), text[i]);
//					//if (it == res.end() - 1) {/* ++a[text[i] - 'a'];*/ continue; }
//					//else
//					//{
//					//	if(*it<*(it+1)) 
//					//	{
//					//		res.erase(it);
//					//		res+= text[i];
//					//	}
//					//}
//					if (it + 1 == res.end() || *it < *(it + 1)) continue;
//					else
//					{
//						res.erase(it);
//					}	res += text[i];
//
//				}
//				else
//					continue;
//			}
//
//		}
//
//		return res;
//	}
//};


class Solution1081 {  
public:
	string smallestSubsequence(string s) {
		int le[26] = { 0 };
		int visit[26] = { 0 };
		vector<char> res;
		res.push_back('0');

//我们一开始给结果字符串res中放个"0"，就是为了在第一次比较时方便，
//如果为空就没法和res中的最后一个字符比较了，而‘0’的ASCII码要小于任意一个字母的，
//所以不会有问题。

		for (auto a : s)
		{
			++le[a - 'a'];
		}
		for (auto a : s)
		{
			--le[a - 'a'];
			if (visit[a - 'a'] == 1) continue;
			while (a < res.back() && le[res.back() - 'a'] > 0)
			{
				visit[res.back() - 'a'] = 0;
				res.pop_back();
			}
			res.push_back(a);
			visit[a - 'a'] = 1;
		}

		string r(res.begin() + 1, res.end());
		return r;
	}
};


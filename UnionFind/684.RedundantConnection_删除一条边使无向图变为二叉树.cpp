
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution2 {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		unordered_map<int, unordered_set<int>> m;
		for (auto i : edges)
		{
			if (helper(i[0], i[1], m, -1)) return i;
			m[i[0]].insert(i[1]);
			m[i[1]].insert(i[0]);
		}
		return {};
	}

	bool helper(int cur, int tar, unordered_map<int, unordered_set<int>>& m, int pre)
	{
		if (m[cur].count(tar)) return true;
		for (auto i : m[cur])
		{
			if (i == pre) continue;
			if (helper(i, tar, m, cur)) return true;
		}

		return false;
	}
};


//其实Union Find的核心思想并不是很难理解，
//首先我们建立一个长度为(n + 1)的数组root，
//由于这道题并没有明确的说明n是多少，
//只是说了输入的二位数组的长度不超过1000，那么n绝对不会超过2000，
//我们加1的原因是由于结点值是从1开始的，而数组是从0开始的，我们懒得转换了，
//就多加一位得了。我们将这个数组都初始化为 - 1，有些人喜欢初始化为i，都可以。
//开始表示每个结点都是一个单独的组，所谓的Union Find就是要让结点之间建立关联，
//比如若root[1] = 2，就表示结点1和结点2是相连的，
//root[2] = 3表示结点2和结点3是相连的，如果我们此时新加一条边[1, 3]的话，
//我们通过root[1]得到2，再通过root[2]得到3，说明结点1有另一条路径能到结点3，
//这样就说明环是存在的；如果没有这条路径，那么我们要将结点1和结点3关联起来，
//让root[1] = 3即可，参见代码如下：



class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> root(2001, -1);
		for (auto i : edges)
		{
			int m = find(i[0], root);
			int n = find(i[1], root);
			if (m == n) return i;
			root[m] = n;
		}
		return {};
	}

	int find(int cur,vector<int>& root)
	{
		while (root[cur] != -1)
		{
			cur = root[cur];
		}
		return cur;
	}
};











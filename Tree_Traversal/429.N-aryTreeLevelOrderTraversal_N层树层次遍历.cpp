#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;


class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};



class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		if (!root) return {};
		vector<vector<int> > res;
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			vector<int> cur;
			for (int i = 0; i != size; ++i)
			{
				Node* t = q.front();
				q.pop();
				cur.push_back(t->val);
				for (auto i : t->children)
					q.push(i);
			}
			res.push_back(cur);
		}
		return res;
	}
};





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
	vector<int> postorder(Node* root) {
		if (!root) return {};
		helper(root);
		return res;
	}
	void helper(Node* cur)
	{
		if (!cur) return;
		for (auto i : cur->children)
			helper(i);

		res.push_back(cur->val);
	}

	vector<int> res;
};


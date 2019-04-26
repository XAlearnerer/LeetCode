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
	int maxDepth(Node* root) {
		if (!root) return 0;
		return helper(root);
	}
	int helper(Node* cur)
	{
		if (!cur) return 0;
		int curm = 0;
		for (auto i : cur->children)
			curm = max(curm, helper(i));
		return curm + 1;

	}

};
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>
#include<sstream>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream os;
		serialize(root, os);
		return os.str();
	}

	void serialize(TreeNode* cur, ostringstream& os)
	{
		if (!cur) os << "# ";
		else
		{
			os << cur->val << " ";
			serialize(cur->left, os);
			serialize(cur->right, os);
		}
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream is(data);
		return deserialize(is);
	}

	TreeNode* deserialize(istringstream& is)
	{
		string val = "";
		is >> val;
		if (val == "#") return NULL;
		TreeNode* cur = new TreeNode(stoi(val));
		cur->left = deserialize(is);
		cur->right = deserialize(is);
		return cur;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));




class Codec3 {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream os;
		serialize(root, os);
		return os.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream is(data);
		return deserialize(is);
	}

	void serialize(TreeNode* root, ostringstream& os) {
		if (!root) os << "# ";
		else {
			os << root->val << " ";
			serialize(root->left, os);
			serialize(root->right, os);
		}
	}

	TreeNode* deserialize(istringstream& is) {
		string val = "";
		is >> val;
		if (val == "#") return NULL;
		TreeNode* node = new TreeNode(stoi(val));
		node->left = deserialize(is);
		node->right = deserialize(is);
		return node;
	}
};







class Codec2 {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (!root) return "";
		ostringstream os;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode *t = q.front(); q.pop();
			if (t) {
				os << t->val << " ";
				q.push(t->left);
				q.push(t->right);
			}
			else {
				os << "# ";
			}
		}
		return os.str();
	}


	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty()) return NULL;
		istringstream is(data);
		queue<TreeNode*> q;
		string val = "";
		is >> val;
		TreeNode *res = new TreeNode(stoi(val)), *cur = res;
		q.push(cur);
		while (!q.empty()) {
			TreeNode *t = q.front(); q.pop();
			if (!(is >> val)) break;
			if (val != "#") {
				cur = new TreeNode(stoi(val));
				q.push(cur);
				t->left = cur;
			}
			if (!(is >> val)) break;
			if (val != "#") {
				cur = new TreeNode(stoi(val));
				q.push(cur);
				t->right = cur;
			}
		}
		return res;
	}
};
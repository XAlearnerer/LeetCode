#include<iostream>
#include<algorithm>
#include<vector>
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
		helpers(root, os);
		return os.str();
	}

	void helpers(TreeNode* root, ostringstream& os)
	{
		if (!root) os << "# ";
		else
		{
			os << root->val << " ";
			helpers(root->left, os);
			helpers(root->right, os);
		}
	}


	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream is(data);
		return helperd(is);

	}

	TreeNode* helperd(istringstream& is)
	{
		string s;
		is >> s;
		if (s == "#") return NULL;
		TreeNode* root = new TreeNode(stoi(s));
		root->left = helperd(is);
		root->right = helperd(is);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));






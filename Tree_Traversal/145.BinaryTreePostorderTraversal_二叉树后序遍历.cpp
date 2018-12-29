//
// Created by zhao on 18-12-29.
//


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using  namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        helper(root);
        return res;
    }
    void helper(TreeNode* root)
    {
        if(!root) return;
        helper(root->left);
        helper(root->right);
        res.push_back(root->val);
    }
    vector<int> res;
};
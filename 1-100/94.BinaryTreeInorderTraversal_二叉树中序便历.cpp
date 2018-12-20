//
// Created by zhao on 18-11-22.
//

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        travel(root,res);
        return res;
    }

    void travel(TreeNode *t,vector<int>& v)
    {
        if(!t)
            return;
        travel(t->left,v);
        v.push_back(t->val);
        travel(t->right,v);
    }
};
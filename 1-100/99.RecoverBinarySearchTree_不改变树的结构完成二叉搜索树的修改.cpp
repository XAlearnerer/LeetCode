//
// Created by zhao on 18-12-21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> treenode;
        vector<int> treeval;
        inorder(root,treenode,treeval);
        sort(treeval.begin(),treeval.end());
        for(int i=0;i!=treenode.size();++i)
            treenode[i]->val=treeval[i];

    }
    void inorder(TreeNode* root,vector<TreeNode*>& treenode, vector<int>& treeval)
    {
        if(!root) return;
        inorder(root->left,treenode,treeval);
        treenode.push_back(root);
        treeval.push_back(root->val);
        inorder(root->right,treenode,treeval);
    }
};
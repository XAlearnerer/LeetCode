//
// Created by Administrator on 2019/4/18.
//
#include <iostream>
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
    int longestUnivaluePath(TreeNode* root) {
        int res=0;
        if(root) helper(root,root->val,res);
        return  res;
    }

    int helper(TreeNode* root,int parent,int& res)
    {
        if(!root) return 0;
        int l=helper(root->left,root->val,res);
        int r=helper(root->right,root->val,res);
        res=max(res,l+r);
        if(root->val==parent) return max(l,r)+1;
        return 0;
    }
};



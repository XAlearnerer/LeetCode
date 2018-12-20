//
// Created by zhao on 18-11-24.
//

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// 任一节点r的左子树中，所有节点均小于r
// 所有右子树中，所有子树均大于r

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;

//        if(root->right==NULL && root->left==NULL)
//            return true;
//        if(root->left==NULL)
//        {
//            if(root->val<root->right->val)
//                return isValidBST(root->right);
//            else
//                return false;
//        }
//
//        if(root->right==NULL)
//        {
//            if(root->val>root->left->val)
//                return isValidBST(root->left);
//            else
//                return false;
//        }

        if(root->val<root->right->val && root->val>root->left->val)
            return isValidBST(root->left)&&isValidBST(root->right);
        else
            return false;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }

    bool helper(TreeNode* root,long min,long max)
    {
        if(root==NULL) return true;
        if(root->val>=max || root->val<=min)
            return false;
        else
            return helper(root->right,root->val,max) && helper(root->left,min,root->val);
    }
};


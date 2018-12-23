//
// Created by zhao on 18-12-22.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using  namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(root->val>sum) return false;
        return helper(root,0,sum);
    }

           //必须为 根节点到叶子节点 路径之和
    bool helper(TreeNode* root,int rootsum, int sum)
    {
        if(!root) return false;
        if(rootsum+root->val == sum) return true;
        if(rootsum+root->val > sum) return false;
        else
            return helper(root->left,rootsum+root->val,sum) || helper(root->right,rootsum+root->val,sum);
    }

};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right && sum==root->val) return true;
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
    }

};
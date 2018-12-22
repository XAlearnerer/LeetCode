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

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return depth(root);
    }
    int depth(TreeNode* root)
    {
        if(!root->left && !root->right) return 1;
        else if(!root->left && root->right) return depth(root->right)+1;
        else if(root->left && !root->right) return depth(root->left)+1;
        else return min(depth(root->right),depth(root->left))+1;
    }
};
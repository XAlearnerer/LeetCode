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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return abs(depth(root->left)-depth(root->right))<2 && isBalanced(root->left) &&
               isBalanced(root->right);
    }
    int depth(TreeNode* root)
    {
        if(!root) return 0;

        // if else 超时
        /*if(depth(root->left)>depth(root->right))
            return depth(root->left)+1;
        else
            return depth(root->right)+1;*/

        return max(depth(root->left),depth(root->right))+1;
    }
};
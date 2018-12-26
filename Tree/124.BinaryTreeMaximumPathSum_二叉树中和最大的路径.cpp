//
// Created by zhao on 18-12-25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using  namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        Max=INT_MIN;
        helper(root);
        return Max;
    }
    int helper(TreeNode* root)
    {
        if(!root) return 0;
        int l=max(0,helper(root->left));
        int r=max(0,helper(root->right));
        Max=max(Max,l+r+root->val);
        return max(l,r)+root->val;
    }
    int Max;
};
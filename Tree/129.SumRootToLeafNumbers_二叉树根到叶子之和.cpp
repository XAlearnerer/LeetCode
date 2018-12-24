//
// Created by zhao on 18-12-24.
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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int sum=0;
        return helper(root,sum);
    }
    int helper(TreeNode* root,int sum)
    {
        if(!root) return 0;
        sum=10*sum+root->val;
        if(!root->right && !root->left) return sum;
        else
            return helper(root->left,sum)+helper(root->right,sum);
    }
};
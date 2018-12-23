//
// Created by zhao on 18-12-23.
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> v;
        helper(res,v,root,sum);
        return res;
    }
    void helper(vector<vector<int>>& res,vector<int>& v,TreeNode* root, int sum)
    {
        if(!root) return;
        v.push_back(root->val);
        if(!root->left && !root->right && sum==root->val) {
            res.push_back(v);
            v.pop_back();
            return;
        }
        helper(res,v,root->left,sum-root->val);
        helper(res,v,root->right,sum-root->val);
        v.pop_back();
    }
};
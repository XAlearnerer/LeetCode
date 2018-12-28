//
// Created by zhao on 18-12-28.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using  namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return res;
    }
    void helper(TreeNode* root)
    {
        if(!root) return;
        helper(root->left);
        res.push_back(root->val);
        helper(root->right);
    }
    vector<int> res;
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        while(1)
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            }
            else if(!s.empty())
            {
                root=s.top();
                s.pop();
                res.push_back(root->val);
                root=root->right;
            }
            else
                break;
        }
        return res;
    }
};
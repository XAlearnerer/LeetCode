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
    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return res;
    }
    void helper(TreeNode* root)
    {
        if(!root)return;
        res.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
    vector<int> res;
};

class Solution3 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        while(1)
        {
            helper(root);
            if(s.empty()) break;
            root=s.top();
            s.pop();
        }
        return res;
    }
    void helper(TreeNode* root)
    {
        while(root)
        {
            res.push_back(root->val);
            s.push(root->right);
            root=root->left;
        }
    }
    vector<int> res;
    stack<TreeNode*> s;
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s{{root}};
        while (!s.empty()) {
            TreeNode *t = s.top();
            s.pop();
            res.push_back(t->val);
            if (t->right) s.push(t->right);
            if (t->left) s.push(t->left);
        }
        return res;
    }
};
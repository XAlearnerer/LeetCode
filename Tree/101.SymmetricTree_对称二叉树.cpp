//
// Created by zhao on 18-12-21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using  namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution3 {  //错误的 [1,2,3,3,null,2,null]
public:
    bool isSymmetric(TreeNode* root) {
        vector<int> Vleft,Vright;
        if(!root) return true;
        inorder(root->left,Vleft);
        inorder(root->right,Vright);
        reverse(Vright.begin(),Vright.end());
        if(Vleft==Vright)
            return true;
        else
            return false;
    }
    void inorder(TreeNode* root,vector<int>& Vvals)
    {
        if(!root)
            return;
        inorder(root->left,Vvals);
        Vvals.push_back(root->val);
        inorder(root->right,Vvals);
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left,root->right);

    }
    bool helper(TreeNode* Left,TreeNode* Right)
    {
        if(!Left && !Right) return true;
        if((!Left && Right) || Left && !Right || Left->val!=Right->val) return false;
        return helper(Left->left,Right->right) && helper(Left->right,Right->left);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode* > Left,Right;
        Left.push(root->left);
        Right.push(root->right);

        while(!Left.empty() && !Right.empty())
        {
            TreeNode* l=Left.front();
            TreeNode* r=Right.front();
            if(!l && r || l && !r) return false;
            Left.pop();
            Right.pop();
            if(l) {
                if (l->val != r->val) return false;
                Left.push(l->left);
                Left.push(l->right);
                Right.push(r->right);
                Right.push(r->left);
            }
        }
        return true;
    }
};
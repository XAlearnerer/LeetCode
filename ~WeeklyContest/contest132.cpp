//
// Created by Administrator on 2019/4/14.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include<bitset>
using namespace std;

class Solution1025 {
public:
    bool divisorGame(int N) {

    }
};




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution1026 {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        vector<int> v;
        dfs(root,v);
        int m=0;
        for(auto a:v)
        {
            m=max(a,m);
        }
        return m;
    }
    //max,min
    pair<int,int> dfs(TreeNode*root,vector<int>& v)
    {
        if (!root->left && !root->right)
        {
            return {root->val,root->val};
        }
        else if(!root->left && root->right)
        {
            pair<int,int> p=dfs(root->right,v);
            v.push_back(minu(p.first,root->val));
            v.push_back(minu(p.second,root->val));
            return  {max(p.first,root->val),min(p.second,root->val)};
        }
        else if(!root->right && root->left)
        {
            pair<int,int> p=dfs(root->left,v);
            v.push_back(minu(p.first,root->val));
            v.push_back(minu(p.second,root->val));
            return  {max(p.first,root->val),min(p.second,root->val)};
        }
        else
        {
            pair<int,int> p1 =dfs(root->left,v);
            pair<int,int> p2 =dfs(root->right,v);
            int x=max(p1.first,p2.first);
            int n=min(p1.second,p2.second);
            v.push_back(minu(x,root->val));
            v.push_back(minu(n,root->val));
            return {max(x,root->val),min(n,root->val)};
        }
    }

    int minu(int a,int b)
    {
        if(a>b) return a-b;
        else
            return b-a;
    }
};



class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {

    }
};

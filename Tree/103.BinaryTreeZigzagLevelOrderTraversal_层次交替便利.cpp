//
// Created by zhao on 18-12-21.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root,res,0);
        for(int i=0;i!=res.size();++i)
        {
            if(i%2!=0)
                reverse(res[i].begin(),res[i].end());
        }
        return res;
    }
    void helper(TreeNode* root,vector<vector<int>>& res,int deepth)
    {
        if(!root) return;
        if(res.size()==deepth)
            res.push_back(vector<int>());
        res[deepth].push_back(root->val);
        helper(root->left,res,deepth+1);
        helper(root->right,res,deepth+1);
    }
};






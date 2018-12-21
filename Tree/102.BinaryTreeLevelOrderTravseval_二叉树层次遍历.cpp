//
// Created by zhao on 18-12-21.
//

#include <iostream>
#include <vector>
#include <queue>
using  namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root,res,0);
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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        typedef pair<TreeNode*, int> Node;
        queue<Node> q;
        q.push(Node(root,0));
        while(!q.empty())
        {
            Node n=q.front();
            q.pop();
            if(!n.first) continue; // 可能出现空指针
            if(n.second==res.size())
                res.push_back(vector<int>());
            res[n.second].push_back(n.first->val);
            q.push(Node(n.first->left,n.second+1));
            q.push(Node(n.first->right,n.second+1));
        }
        return res;
    }
};





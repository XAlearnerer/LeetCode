//
// Created by zhao on 18-12-25.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            res.push_back(q.back()->val);
            int size= q.size();
            for(int i=0;i<size;++i)
            {
                TreeNode* r=q.front();
                q.pop();
                if(r->left) q.push(r->left);
                if(r->right) q.push(r->right);
            }
        }
        return res;
    }
};
//
// Created by zhao on 18-12-21.
//
#include <iostream>
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        typedef pair<TreeNode*, int> Node;
        int maxdep=0;
        queue<Node> q;
        q.push(Node(root,1));
        while(!q.empty())
        {
            Node n=q.front();
            q.pop();
            if(!n.first) continue;
            if(n.second>maxdep)
                maxdep=n.second;
            q.push(Node(n.first->left,n.second+1));
            q.push(Node(n.first->right,n.second+1));
        }
        return maxdep;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        //return maxDepth(root->left)>maxDepth(root->right)?1+maxDepth(root->left):1+maxDepth(root->right);
        return 1+ max(maxDepth(root->left),maxDepth(root->right));
    }
};
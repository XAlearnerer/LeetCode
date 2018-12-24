//
// Created by zhao on 18-12-23.
//

#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

//=================== 递归解法 ============================
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) root->left->next = root->right;
        if (root->right) root->right->next = root->next? root->next->left : NULL;
        connect(root->left);
        connect(root->right);
    }
};

//=================== 以下为非递归算法 ============================

class Solution2 {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                TreeLinkNode* cur=q.front();
                q.pop();
                if(n>0) cur->next=q.front();
                else cur->next=NULL;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
    }
};

class Solution3 {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode *start, *cur;
        start=root,cur=NULL;
        root->next=NULL;
        while(start->left)
        {
            cur=start;
            while(cur)
            {
                cur->left->next=cur->right;
                if(cur->next)
                   cur->right->next=cur->next->left;
                else
                   cur->right->next=NULL;
                cur=cur->next;
            }
            start=start->left;
        }
    }
};

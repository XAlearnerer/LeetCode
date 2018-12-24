//
// Created by zhao on 18-12-24.
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
        if(!root) return;
        TreeLinkNode* Nex=root->next;
        while(Nex)
        {
            if(Nex->left) {
                Nex = Nex->left;
                break;
            }
            if(Nex->right)
            {
                Nex=Nex->right;
                break;
            }
            Nex=Nex->next;
        }
        if(root->right)
            root->right->next=Nex;
        if(root->left) {
            if(root->right)
                root->left->next =root->right;
            else
                root->left->next=Nex;
        }

        connect(root->right);
        connect(root->left);
        //connect(root->right);
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
        TreeLinkNode *dummy = new TreeLinkNode(0), *cur = dummy;
        while (root) {
            if (root->left) {
                cur->next = root->left;
                cur = cur->next;
            }
            if (root->right) {
                cur->next = root->right;
                cur = cur->next;
            }
            root = root->next;
            if (!root) {
                cur = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
    }
};


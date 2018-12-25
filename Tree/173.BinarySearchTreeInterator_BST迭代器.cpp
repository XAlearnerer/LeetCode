//
// Created by zhao on 18-12-24.
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

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        helper(root);
        vit=0;
    }

    void helper(TreeNode *root)
    {
        if(!root) return;
        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(vit<v.size())
            return true;
        else
            return false;
    }

    /** @return the next smallest number */
    int next() {
        vit++;
        return v[vit-1];
    }
    vector<int> v;
    int vit;
};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
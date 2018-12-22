//
// Created by zhao on 18-12-21.
//

#include <iostream>
#include <algorithm>
#include <vector>
using  namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder,int pl,int pr, vector<int>& inorder,int il,int ir)
    {
        if(pl>pr || il>ir) return NULL;
        int gap;
        for(gap=il;gap<=ir;++gap)
            if(preorder[pl]==inorder[gap])
                break;
        TreeNode* root=new TreeNode(preorder[pl]);
        root->left=helper(preorder,pl+1,pl+gap-il,inorder,il,gap-1);
        root->right=helper(preorder,pl+gap-il+1,pr,inorder,gap+1,ir);
        return root;
    }
};

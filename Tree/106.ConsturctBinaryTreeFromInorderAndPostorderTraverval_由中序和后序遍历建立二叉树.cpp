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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* helper(vector<int>& inorder,int il,int ir, vector<int>& postorder,int pl,int pr)
    {
        if(il>ir || pl>pr) return NULL;
        int gap=il;
        for(;gap<=ir;++gap)
            if(inorder[gap]==postorder[pr]) break;
        TreeNode* root=new TreeNode(postorder[pr]);
        root->left=helper(inorder,il,gap-1,postorder,pl,pl+gap-il-1);
        root->right=helper(inorder,gap+1,ir,postorder,pl+gap-il,pr-1);
        return root;
    }
};

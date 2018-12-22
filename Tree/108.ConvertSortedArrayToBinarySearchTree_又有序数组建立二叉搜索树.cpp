//
// Created by zhao on 18-12-22.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums,int lef,int rig)
    {
        if(lef>rig)
            return NULL;
        int mid=(lef+rig)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper(nums,lef,mid-1);
        root->right=helper(nums,mid+1,rig);
        return root;
    }
};
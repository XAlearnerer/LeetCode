//
// Created by zhao on 19-5-14.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution2 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        vector<int> temp;
        for(int i=nums.size()-1;i>=0;--i)
        {
            int dis=distance(temp.begin(),lower_bound(temp.begin(),temp.end(),nums[i]));
            res[i]=dis;
            temp.insert(temp.begin()+dis,nums[i]);
        }
        return  res;
    }
};

////   vector<int>temp is served to store all right number of nums[i] ascending


class Solution3 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        vector<int> temp;
        for(int i=nums.size()-1;i>=0;--i)
        {
            int left=0,//right=temp.size()-1;
            right = temp.size();
            while(left<right)
            {
                int mid=(left+right)/2;
                if(nums[i]<=temp[mid]) right=mid;
                else left=mid+1;
            }

            res[i]=right;
            temp.insert(temp.begin()+right,nums[i]);
        }
        return res;

    }
};




class Solution
{
public:
    struct node {
        int val, smaller;
        node *left, *right;
        node(int v, int s) : val(v), smaller(s), left(NULL), right(NULL) {}
    };
    int insert(node* &root,int v)
    {
        if (!root) {root = new node(v, 0);return  0;}
        if (root->val > v) {root->smaller++; return insert(root->left, v);}
        else return insert(root->right, v) + root->smaller + (root->val < v ? 1 : 0);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        node *root = NULL;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};


//int main()
//{
//    vector<int> nums={5,2,6,1};
//    Solution n;
//    for(auto i:n.countSmaller(nums))
//        cout<<i<<" ";
//
//    return 0;
//}

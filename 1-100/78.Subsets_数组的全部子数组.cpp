//
// Created by zhao on 18-11-9.
//

#include <vector>
#include <iostream>
using namespace std;

#include <algorithm>

class Solution2 {  //超时了
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(nums);
        if(nums.empty()) return res;
        for(int i=nums.size()-1;i>0;--i)
        {
            Per(res,0,nums,i);
        }
        res.push_back({});
        return res;

    }

    void Per(vector<vector<int> > &res,int begin, vector<int> nums,int length)
    {
        if (begin == length)
        {
            vector<int> v(nums.begin(),nums.begin()+begin);
            sort(v.begin(),v.end());
            if(find(res.begin(),res.end(),v)!=res.end()) return;
            res.push_back(v);
            return;
        }

        for (int i = begin; i != nums.size(); ++i)
        {
            swap(nums[begin], nums[i]);
            Per(res ,begin + 1, nums,length);
            swap(nums[begin], nums[i]);
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) {
            res.push_back({});
            return res;
        }
        vector<int> vv;
        Per(res,0,nums,vv);
        return res;

    }

    void Per(vector<vector<int> > &res,int begin, vector<int> nums,vector<int>& vv)
    {
        res.push_back(vv);
        for (int i = begin; i != nums.size(); ++i)
        {
            vv.push_back(nums[i]);
            Per(res ,i + 1, nums,vv);
            vv.pop_back();
        }
    }
};


int main1053()
{
    Solution n;
    vector<int> v={1,2,3};

    vector<vector<int> >vv = n.subsets(v);
    for (auto i : vv) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

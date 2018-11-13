//
// Created by zhao on 18-11-12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> com;
        process(res,com,nums,0);
        return res;
    }


    void process(vector<vector<int>>& res,vector<int> com,vector<int>& nums,int begin)
    {
        res.push_back(com);
        for (int i = begin; i != nums.size(); ++i)
        {
            if(i>begin && nums[i]==nums[i-1]) continue;
            com.push_back(nums[i]);
            process(res ,com, nums,i+1);
            com.pop_back();
        }
    }
};
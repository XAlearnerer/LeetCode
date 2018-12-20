//
// Created by zhao on 18-10-23.
//
#include <vector>
#include <iostream>
using  namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]>=target) return i;
            if(nums[i]<target)
                ++i;
            if(nums[nums.size()-1]<target) return (int)nums.size();
        }

    }
};
//
// Created by zhao on 19-4-3.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using  namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        bool res=false;
        for(int i=0;i!=nums.size();++i)
        {
            if(map.count(nums[i])==0)
                map[nums[i]]=i;
            else
            {
                if(i-map[nums[i]]<=k)
                    return true;
                else
                {
                    res=false;
                    map[nums[i]]=i;
                }
            }
        }
        return res;
    }
};


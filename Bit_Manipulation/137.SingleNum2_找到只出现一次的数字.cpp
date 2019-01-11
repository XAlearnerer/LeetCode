//
// Created by zhao on 19-1-11.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int low = 0, high = 0;
        int len=nums.size();
        for(int i = 0; i < len; i++){
            low = (low ^ nums[i]) & ~high;
            high = (high ^ nums[i]) & ~low;
        }
        return low;
    }
};
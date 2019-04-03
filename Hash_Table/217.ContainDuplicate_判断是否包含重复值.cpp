//
// Created by zhao on 19-4-3.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using  namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(auto a:nums)
            if(set.count(a)!=0) return true;
            else
                set.insert(a);
        return false;
    }
};

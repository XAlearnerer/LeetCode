//
// Created by zhao on 19-5-14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left=1,right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            int count=0;
            for(auto i:nums)
                if(i<=mid) ++count;
            if(count>mid) right=mid;
            else left=mid+1;
        }

        return left;
    }
};
//
// Created by zhao on 19-5-13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[left]<nums[right])
            {
                break;
            }
            else
            {
                if(nums[mid]<nums[left])
                    right=mid;
                ////  right = mid - 1   is worng   example: [3,1,2]
                else
                    left=mid+1;
            }
        }
        return nums[left];

    }
};
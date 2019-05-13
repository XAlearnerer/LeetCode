//
// Created by zhao on 19-5-13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size();
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[left]>nums[right]) {
                if (nums[left] >= nums[mid]) {
                    left = mid + 1;
                }
                else(nums[left] < nums[mid])
                {
                    right=mid;
                }
            }
            else if(nums[left]<nums[right])
            {
                break;
            }
            else
            {
                while(left<right && nums[left]==nums[left+1])
                    ++left;
            }

        }

        return nums[left];
    }
};
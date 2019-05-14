//
// Created by zhao on 19-5-13.
//

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]<nums[right])
            {
                right=mid;
            }
            else if(nums[mid]>nums[right])
            {
                left=mid+1;
            }
            else
            {
                --right;
            }

        }
        return nums[left];
    }
};



class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int res=INT_MAX;
        while(left<right-1)
        {
            int mid=(left+right)/2;
            if(nums[left]<nums[mid])
            {
                res=min(res,nums[left]);
                left=mid+1;
            }
            else if(nums[left]>nums[mid])
            {
                res=min(res,nums[mid]);
                right=mid;
            }
            else
                ++left;
        }

        res=min(res,nums[left]);
        res=min(res,nums[right]);
        return res;

//        while(left<right)
//        {
//            int mid=(left+right)/2;
//            if(nums[left]>nums[right]) {
//                if (nums[left] >= nums[mid]) {
//                    left = mid + 1;
//                }
//                else
//                {
//                    right=mid;
//                }
//            }
//            else if(nums[left]<nums[right])
//            {
//                break;
//            }
//            else
//            {
//                while(left<right && nums[left]==nums[left+1])
//                    ++left;
//            }
//        }

//       return nums[left];

    }
};


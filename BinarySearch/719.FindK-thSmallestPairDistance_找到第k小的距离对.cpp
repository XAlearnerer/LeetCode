//
// Created by zhao on 19-5-13.
//

//Find K Pairs with Smallest Sums
//Kth Smallest Element in a Sorted Matrix
//Find K Closest Elements
//Kth Smallest Number in Multiplication Table
//K-th Smallest Prime Fraction

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0,right=nums.back()-nums[0];

        while (left < right) {
            int mid = (right + left) / 2, cnt = 0, start = 0;
            for(int i=0;i<nums.size();++i)
            {
                while (start < n && nums[i] - nums[start] > mid) ++start;
                cnt += i - start;
            }

            if (cnt < k) left = mid + 1;
            else right = mid;
        }

        return right;
    }
};
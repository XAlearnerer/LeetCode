//
// Created by zhao on 18-10-25.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution2 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            if(nums[i]==i+1)
                ++i;
            else if(nums[i]<=0 || nums[i]>nums.size() || nums[nums[i] - 1] == nums[i])
            {
                nums[i]=nums[j];
                --j;
            }
            else
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        return i+1;

    }
};


class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n=nums.size();
        for(int i = 0; i < n; ++ i)
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);

        for(int i = 0; i < n; ++ i)
            if(nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};
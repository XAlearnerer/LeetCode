//
// Created by zhao on 18-11-8.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, right = nums.size();
        int index = 0;
        while (index < right)
        {
            if (nums[index] == 0)
            {
                swap(nums[++left], nums[index]);
                ++index;
            }
            else if (nums[index] == 1)
            {
                ++index;
            }
            else
            {
                swap(nums[--right], nums[index]);
            }
        }

    }
};


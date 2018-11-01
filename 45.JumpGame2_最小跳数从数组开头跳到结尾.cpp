//
// Created by zhao on 18-10-31.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int begin=0;
        int k=1;
        while(begin<nums.size())
        {
            if(begin+nums[begin]>=nums.size()-1)
                return k;
            int max =0;
            int maxi =0;
            ++k;

            for(int i=1;i<=nums[begin];++i)
            {
                if(nums[i + begin]==0) continue;
                if(nums[i + begin] + i + begin>= max)
                {
                    max = nums[i + begin] + i + begin;
                    maxi=i+begin;
                }
            }
            begin = maxi;

        }
    }
};

int main1015()
{
    vector<int> v={2,3,1,1,4};
    Solution n;
    cout<<n.jump(v)<<endl;
    return 0;
}
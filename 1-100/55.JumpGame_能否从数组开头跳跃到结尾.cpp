//
// Created by zhao on 18-11-12.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int begin=0;
        int lastbe=0;

        while(begin<=nums.size())
        {
            if(begin+nums[begin]>=nums.size()-1)
                return true;
            else
            {
                int max=-1,maxi=0;
                for(int i=0;i<=nums[begin];++i)
                {
                    if(!nums[begin+i]) continue;
                    if(begin+nums[i+begin]+i>max)
                    {
                        max=begin+nums[i+begin]+i;
                        maxi=i+begin;
                    }
                }
                begin=maxi;
            }
            if(begin==lastbe)
                return false;
            else
                lastbe = begin;
        }
    }
};



int main1538()
{
    vector<int> v={0};
    Solution n;
    cout<<n.canJump(v)<<endl;

    return 0;
}




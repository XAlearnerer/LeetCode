//
// Created by zhao on 19-4-20.
//

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        nums.push_back(1);
        nums.insert(nums.begin(),1);


        for(int level=1;level<=n;++level)
        {
            for (int i = 1; i <= n-level+1; ++i)
            {
                int j=i+level-1;
                for(int k=i;k<=j;++k)
                {
                    dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+nums[k]*nums[i-1]*nums[j+1]);
                }
            }
        }

        return dp[1][n];
    }
};



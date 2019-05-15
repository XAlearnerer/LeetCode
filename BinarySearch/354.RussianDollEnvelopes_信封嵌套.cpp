//
// Created by zhao on 19-5-15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//// Like    LeetCode 300.LongestIncreasingSequence
//// Really

class Solution2 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int res=0,n=envelopes.size();
        vector<int> dp(n,1);
        sort(envelopes.begin(),envelopes.end());
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1])
                    dp[i]=max(dp[i],dp[j]+1);
            }
            res=max(res,dp[i]);
        }

        return res;

    }
};


class Solution3 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> res;
        sort(envelopes.begin(),envelopes.end(),[](vector<int> v1,vector<int> v2)
        { if(v1[0]==v2[0]) return v1[1]>v2[1];  else return v1[0]<v2[0];} );
        for(int i=0;i<envelopes.size();++i)
        {
            auto it=lower_bound(res.begin(),res.end(),envelopes[i][1]);
            if(it==res.end()) res.push_back(envelopes[i][1]);
            else *it=envelopes[i][1];
        }

        return res.size();

    }
};


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> res;
        sort(envelopes.begin(),envelopes.end(),[](vector<int> v1,vector<int> v2)
        { if(v1[0]==v2[0]) return v1[1]>v2[1];  else return v1[0]<v2[0];} );

        for(int i=0;i<envelopes.size();++i)
        {
            int left=0,right=res.size();
            while(left<right)
            {
                int mid=(left+right)/2;
                if(res[mid]<envelopes[i][1])
                    left=mid+1;
                else right=mid;
            }
            if(right>=res.size()) res.push_back(envelopes[i][1]);
            else res[right]=envelopes[i][1];
        }

        return res.size();

    }
};




//
// Created by zhao on 19-5-22.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include<bitset>
#include <unordered_map>
#include <map>

using namespace std;

class Solution883 {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;++i)
        {
            int cur=0;
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]!=0) ++res;
                cur=max(cur,grid[i][j]);
            }
            res+=cur;
        }

        for(int i=0;i<m;++i)
        {
            int cur=0;
            for(int j=0;j<n;++j)
            {
                cur=max(cur,grid[j][i]);
            }
            res+=cur;
        }

        return res;
    }
};


//////////////////////////////////////////////////////////////////


//class Solution {
//public:
//    int numRescueBoats(vector<int>& people, int limit) {
//        int res=0;
//        sort(people.begin(),people.end(),greater<int>());
//        vector<int> dp(people.size(),0);
//        vector<int> vis(people.size(),0);
//
//        for(int i=0;i<limit;++i)
//        {
//           for(int j=0;j<people.size();++j)
//           {
//               dp[i]=min(dp[i],1+dp[i-people[j]]);
//           }
//        }
//
//
//
//
//    }
//};


// 一条船　只有两个人
class Solution881 {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0,j=people.size()-1;
        sort(people.begin(),people.end(),greater<int>());
        while(i<=j)
        {
            if(people[i]+people[j]<=limit) --j;
            ++i;
        }

        return i;
    }
};









///////////////////////////////////////////////////////////////////

//多个数字相连的话要拼成个多位数，但实际上是分开的，比如例子2中的 ha22，
// 第一个2是将 ha 重复两次，第二个2是将 haha 重复两次

class Solution880 {
public:
    string decodeAtIndex(string S, int K) {
        long len = 0, i;

        for (i = 0; len < K; i++) {
            if (S[i] >= 'a' && S[i] <= 'z') len++;
            else len *= (S[i] - '0');
        }

        do {
            i--;
            if (S[i] >= '0' && S[i] <= '9') {
                len /= (S[i] - '0');
                K %= len;
            }
            else {
                if (!(K%len)) return string(1, S[i]);
                len--;
            }
        } while (i);
    }
};



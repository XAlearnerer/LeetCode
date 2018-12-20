//
// Created by zhao on 18-12-20.
//
#include <iostream>
#include <string>
#include <vector>
using  namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        dp[0][0]=0;
        for(int i=1;i<=m;++i)
            dp[i][0]=i;
        for(int i=0;i<=n;++i)
            dp[0][i]=i;

        for(int i=1;i<=m;++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = findmin(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp[m][n];
    }

    int findmin(int a,int b,int c)
    {
        int min=a;
        if(min>b) min=b;
        if(min>c) min=c;
        return min;
    }
};
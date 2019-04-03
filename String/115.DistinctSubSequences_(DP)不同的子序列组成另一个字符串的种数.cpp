//
// Created by zhao on 19-4-3.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  Ø r a b b b i t
//Ø 1 1 1 1 1 1 1 1
//r 0 1 1 1 1 1 1 1
//a 0 0 1 1 1 1 1 1
//b 0 0 0 1 2 3 3 3
//b 0 0 0 0 1 3 3 3
//i 0 0 0 0 0 0 3 3
//t 0 0 0 0 0 0 0 3

class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        //vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        //vector<vector<long>> dp(m+1,vector<long>(n+1,0));
        vector<vector<uint>> dp(m+1,vector<uint>(n+1,0));

//        int是带符号的，表示范围是：-2147483648到2147483648，即-2^31到2^31次方。
//        uint则是不带符号的，表示范围是：2^32即0到4294967295。



        dp[0][0]=1;
        for(int i=1;i!=m+1;++i) dp[i][0]=0;
        for(int j=1;j!=n+1;++j) dp[0][j]=1;
        for(int i=1;i!=m+1;++i) {
            for (int j = 1; j != n + 1; ++j)
            {
                if(s[j-1]==t[i-1]) // 注意这里
                {
                    dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }

        return dp[m][n];
    }
};


//int main()
//{
//    string S = "rabbbit", T = "rabbit";
//    Solution n;
//    cout<<n.numDistinct(S,T)<<endl;
//    return 0;
//}

//
// Created by zhao on 18-12-1.
//

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,0);
        int i=1;
        dp[0]=1;
        while(i<dp.size())
        {
            dp[i]=s[i-1]=='0'?0:dp[i-1];
            if(i>1 && (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6')))
                dp[i]+=dp[i-2];
            ++i;
        }
        return dp.back();
    }
};

int main()
{
    string s="0";
    Solution n;
    cout<<n.numDecodings(s)<<endl;
    return 0;
}
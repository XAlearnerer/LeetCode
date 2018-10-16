//
// Created by zhao on 18-10-16.
//

#include <iostream>
#include <string>
using namespace std;

#include <map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int *A=new int[256];
        for(int i=0;i!=256;++i)
        {
            A[i]=-1;
        }

        int len=0;
        int begin=0;
        int cur=0;
        for(int i=0;i!=s.length();++i)
        {
            if(A[s[i]]!=-1)
            {
                if(A[s[i]] >= begin)
                    begin=A[s[i]]+1;
            }
            A[s[i]]=i;
            cur=i-begin +1;
            if(cur>len) len=cur;
        }

        return len;
    }
};




int main()
{
    string s="pwwkew";
    Solution n;
    cout<<n.lengthOfLongestSubstring(s)<<endl;


    return 0;
}
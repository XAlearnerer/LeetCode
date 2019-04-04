//
// Created by zhao on 19-4-4.
//

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        int a[26]={0};
        for(int i=0;i!=s.length();++i)
        {
            ++a[s[i]-'a'];
        }
        for(int i=0;i!=s.length();++i)
        {
            if(a[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};

//
// Created by zhao on 19-4-3.
//

#include <iostream>
using  namespace std;


/////使用数组代替哈希
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        int a[26]={0};
        for(int i=0;i!=s.length();++i)
        {
            ++a[s[i]-'a'];
        }
        for(int i=0;i!=t.length();++i)
        {
            --a[t[i]-'a'];
        }
        for(int i=0;i!=26;++i)
            if(a[i]!=0)
                return false;
         return true;

    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        int a[26]={0};
        for(int i=0;i!=s.length();++i)
        {
            ++a[s[i]-'a'];
            --a[t[i]-'a'];
        }
        for(int i=0;i!=26;++i)
            if(a[i]!=0)
                return false;
        return true;

    }
};



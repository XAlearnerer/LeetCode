//
// Created by zhao on 19-4-3.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    bool isIsomorphic(string s, string t) {
//        if(s.length()!=t.length())
//            return false;
//        unordered_map<char,char> map;
//        for(int i=0;i!=s.length();++i)
//        {
//            if(map.count(s[i])==0)
//            {
//                map[s[i]]=t[i];
//            }
//            else
//            {
//                if(t[i]!=map[s[i]])
//                    return false;
//            }
//        }
//        return true;
//    }
//};
//


/////   一对一 需要两个哈希表
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        int a[256]={0};
        int b[256]={0};
        for(int i=0;i<s.length();++i)
        {
            if(a[s[i]]!=b[t[i]]) return false;
            a[s[i]]=i+1;
            b[t[i]]=i+1;
        }
        return true;

    }
};

//
// Created by zhao on 19-4-4.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26]={0};
        for(int i=0;i!=magazine.size();++i)
        {
            ++a[magazine[i]-'a'];
        }
        for(int i=0;i!=ransomNote.size();++i)
        {
            //--a[ransomNote[i]-'a'];
            if(--(a[ransomNote[i]-'a'])<0)
                return false;
        }
        return true;
    }
};


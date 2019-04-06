//
// Created by zhao on 19-4-6.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==1) return true;

        for(int i=1;i!=word.size();++i)
        {
            if(word[0]<='Z') //大写
            {
                if(word[1]<='Z') //大写
                {
                    if(word[i]>'Z')
                        return false;
                }
                else
                {
                    if(word[i]<='Z') //大写
                        return false;
                }
            }
            else
            {
                if(word[i]<='Z') //大写
                    return false;
            }

        }
        return true;
    }
};

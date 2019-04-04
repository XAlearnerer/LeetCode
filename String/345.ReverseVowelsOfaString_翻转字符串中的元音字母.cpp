//
// Created by zhao on 19-4-4.
//

#include <iostream>
#include <string>
#include <unordered_set>

using  namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};
        int begin=0,end=s.size()-1;
        while(begin<end)
        {
            while(vowels.count(s[begin])==0 && begin<end)
                ++begin;
            while(vowels.count(s[end])==0 && begin<end)
                --end;
            if(begin>=end) return s;
            swap(s[begin],s[end]);
            ++begin;
            --end;
        }
        return s;
    }
};



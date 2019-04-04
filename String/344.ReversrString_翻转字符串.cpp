//
// Created by zhao on 19-4-4.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution2 {
public:
    void reverseString(vector<char>& s) {
        int begin=0,end=s.size()-1;
        while(begin<end) {
            swap(s[begin], s[end]);
            ++begin;
            --end;
        }
    }
};


class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0;i<s.size()/2;++i)
        {
            int j=s.size()-1-i;
            char m=s[i];
            s[i]=s[j];
            s[j]=m;
        }
    }
};


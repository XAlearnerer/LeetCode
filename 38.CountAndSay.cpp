//
// Created by zhao on 18-10-23.
//
#include <iostream>
using namespace std;
#include <string>


class Solution2 {
public:
    string countAndSay(int n) {
        if(n<1 || n>30)
            return "";
        if(n==1) return "1";
        int count=1;
        string s="1";
        string ss;
        while(1) {
            s =  syoutube(s, count);
            if(count == n)
                break;
        }
        return s;
    }

    string syoutube(string s,int& count)
    {
        string result="";

        int i=0,j=1;
        while(j!=s.length())
        {
            if(s[i]==s[j])
                ++j;
            else
            {
                result=result+to_string(j-i)+s[i];
                i=j;
            }
        }
        result=result+to_string(j-i)+s[i];
        ++count;
        return result;

    }
};


class Solution3 {
public:
    string countAndSay(int n) {
        if(n<1 || n>30)
            return "";
        if(n==1) return "1";
        string s=countAndSay(n-1);

        string result="";
        int i=0,j=1;
        while(j!=s.length())
        {
            if(s[i]==s[j])
                ++j;
            else
            {
                result=result+to_string(j-i)+s[i];
                i=j;
            }
        }
        result=result+to_string(j-i)+s[i];
        return result;
    }
};

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";

        string s = "1";

        for (int k = 1; k< n; ++k) {
            string result="";
            int i=0,j=1;
            while(j!=s.length())
            {
                if(s[i]==s[j])
                    ++j;
                else
                {
                    result=result+to_string(j-i)+s[i];
                    i=j;
                }
            }
            result=result+to_string(j-i)+s[i];
            s = result;
        }
        return s;
    }
};


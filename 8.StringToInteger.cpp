//
// Created by zhao on 18-10-15.
//
#include <iostream>
using namespace std;

//#include <math.h>
class Solution {
public:
    int myAtoi(string str) {
        if(str[0]!= '-' && (str[0] > '9' || str[0] <'0') && str[0] != ' ' && str[0]!= '+')
            return 0;
        if(str.length()==0) return 0;

        int begin=0;
        if(str[0]==' ') {
            while (str[begin]==' ')
                ++begin;
        }

        long num = 0;
        if(str[begin]=='-')
        {
            ++begin;
            while(str[begin]>='0' && str[begin] <= '9'&& begin<str.length())
            {
                num=num*10+(str[begin]-'0');
                ++begin;
                if(num>INT_MAX)
                    return INT_MIN;
            }
            return num<INT_MAX?-(int)num:INT_MIN+1;
        }
        else if(str[begin]>='0' && str[begin] <= '9')
        {
            num=num*10+(str[begin]-'0');
            ++begin;
            while(str[begin]>='0' && str[begin] <= '9' && begin<str.length())
            {
                num=num*10+(str[begin]-'0');
                ++begin;
                if(num>pow(2,31))
                    return INT_MAX;
            }
            return num<INT_MAX?(int)num:INT_MAX;

        }
        else if(str[begin]=='+')
        {
            ++begin;
            while(str[begin]>='0' && str[begin] <= '9'&& begin<str.length())
            {
                num=num*10+(str[begin]-'0');
                ++begin;
                if(num>INT_MAX)
                    return INT_MAX;
            }
            return num<INT_MAX?(int)num:INT_MAX;
        }

        else
            return 0;


    }
};

int main()
{
    string s="-2147483647";

    Solution n;
    cout<<n.myAtoi(s)<<endl;


    return 0;
}
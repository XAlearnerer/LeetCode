//
// Created by zhao on 18-10-15.
//
#include <iostream>
using namespace std;
#include <limits.h>


/*
    INT_MIN在标准头文件limits.h中定义。

    #define INT_MAX 2147483647
    #define INT_MIN (-INT_MAX - 1)

    在C/C++语言中，不能够直接使用-2147483648来代替最小负数，因为这不是一个数字，而是一个表达式。表达式的意思是对整数21473648取负，
    但是2147483648已经溢出了int的上限，所以定义为（-INT_MAX -1）。

    C中int类型是32位的，范围是-2147483648到2147483647 。
    （1）最轻微的上溢是INT_MAX + 1 :结果是 INT_MIN;
    （2）最严重的上溢是INT_MAX + INT_MAX :结果是-2;
    （3）最轻微的下溢是INT_MIN - 1:结果是是INT_MAX;
    （4）最严重的下溢是INT_MIN + INT_MIN:结果是0 。

 */
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
                if(num>INT_MAX)
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

int main2237()
{
    string s="-2147483647";

    Solution n;
    cout<<n.myAtoi(s)<<endl;


    return 0;
}
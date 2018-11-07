//
// Created by zhao on 18-11-6.
//
#include <iostream>
#include <vector>
using namespace std;

#include <algorithm>

class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.length();
        int n=b.length();
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int min,max;
        if(m>n){min=n;max=m;}
        else {min=m;max=n;}
        string s(max+1,'0');

        int ch=0, i=0;
        while(i!=min)
        {
            if(a[i]-'0'+b[i]-'0'+ch < 2)
            {
                s[i]=(char)(a[i]-'0'+b[i]+ch);
                ch=0;
            }
            else
            {
                s[i]=(char)(a[i]-'0'+b[i]+ch-2);
                ch=1;
            }
            ++i;
        }
        while(i<a.length())
        {
            if(a[i]-'0'+ch < 2)
            {
                s[i]=(char)(a[i]+ch);
                ch=0;
            }
            else
            {
                s[i]=(char)(a[i]+ch-2);
                ch=1;
            }
            ++i;
        }
        while(i<b.length())
        {
            if(b[i]-'0'+ch < 2)
            {
                s[i]=(char)(b[i]+ch);
                ch=0;
            }
            else
            {
                s[i]=(char)(b[i]+ch-2);
                ch=1;
            }
            ++i;
        }
        s[s.length()-1]=ch+'0';
        if(s[s.length()-1]=='0')
        {
            s.resize(s.length()-1);
        }
        reverse(s.begin(),s.end());

        return  s;
    }
};

class Solution2
{
public:
    string addBinary(string a, string b)
    {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }

        return s;
    }
};



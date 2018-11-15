//
// Created by zhao on 18-11-12.
//
#include <iostream>
#include <string>
#include <vector>
//#include<Windows.h>
using  namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        string str = init(s);
        vector<int> v(str.length());
        int mx=0,longest=-1,id=0,longestid=0;

        for(int i=0;i!=str.length();++i)
        {
            if(i<mx)
                v[i]=min(v[2*id-i],mx-i);
            else
                v[i]=1;

            //while(str[i-v[i]]==str[i+v[i]] && i>=0 && i<str.length())
            while(str[i-v[i]]==str[i+v[i]] && i-v[i]>=0 && i+v[i]<str.length())
                v[i]++;

            if(mx<i+v[i])
            {
                id=i;
                mx=i+v[i];
            }
//            if(v[i]-1>longest) {
//                longest = v[i] - 1;
//                longestid=id;
//            }

            if(v[i]>longest) {
                longest = v[i];
                longestid=id;
            }
        }
        string r;
        r.assign(str.begin()+longestid-longest+1,str.begin()+longestid+longest);

        string res(r.length(),'0');
        int i=0,j=0;
        for(;i<r.length();++i)
        {
            if(r[i]!='#')
                res[j++]=r[i];
        }
        res.resize(j);
        return  res;

    }

    string init(string s)
    {
        string str(2*s.length()+1,'0');
        int j=1;
        str[0]='#';
        for(int i=0;i!=s.length();++i)
        {
            str[j++]=s[i];
            str[j++]='#';
        }
        return str;
    }
};


int main1116()
{
    string s="babad";
    Solution n;
    cout<<n.longestPalindrome(s)<<endl;
    return 0;
}


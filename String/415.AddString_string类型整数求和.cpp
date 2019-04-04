//
// Created by zhao on 19-4-4.
//

#include <iostream>
#include <string>
#include <algorithm>
using  namespace std;

//////  有 进位 未考虑
//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        string sh,lo;
//        if(num1.length()<num2.length()) {
//            sh.assign(num1.rbegin(),num1.rend());
//            lo.assign(num2.rbegin(),num2.rend());
//        }
//        else
//        {
//            sh.assign(num2.rbegin(),num2.rend());
//            lo.assign(num1.rbegin(),num1.rend());
//        }
//
//        string res;
//        int i=0;
//        for(;i!=sh.size();++i)
//        {
//            res+=sh[i]-'0'+lo[i];
//        }
//        for(;i!=lo.size();++i)
//        {
//            res+=lo[i];
//        }
//        cout<<res<<endl;
//
//        res.assign(res.rbegin(),res.rend());
//        return res;
//
//    }
//};

class Solution2 { //// 错误
public:
    string addStrings(string num1, string num2) {
        string res="";
        int sum=0;
        int carry=0;
        int i=num1.size()-1,j=num2.size()-1;
        while(i>=0 && j>=0)
        {
            sum=sum+(num1[i]-'0')+(num2[i]-'0') + carry;
            carry = sum/10;
            sum%=10;
            res+=to_string(sum);
            --i;
            --j;
        }

        //// 这样写的话之后还要写好多

        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.length()-1,j=num2.length()-1;
        int carry=0;
        string res="";
        while(i>=0 || j>=0 || carry)
        {
            int sum=0;
            if(i>=0) {sum+=(num1[i]-'0');--i;}
            if(j>=0) {sum+=(num2[j]-'0');--j;}
            sum+=carry;
            carry=sum/10;
            sum%=10;
            res+=to_string(sum);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
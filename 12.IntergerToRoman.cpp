//
// Created by zhao on 18-10-18.
//

#include <iostream>
#include <vector>
#include <string>
using  namespace std;
/*
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
 */
class Solution2 {
public:
    string intToRoman(int num) {
        string s="";
        int i=1;
        string one,five,ten;
        while(num)
        {
            if(i==1)
            {
                one="I";
                five="V";
                ten="X";
            }
           if(i==2)
            {
                one="X";
                five="L";
                ten="C";
            }
            if(i==3)
            {
                one="C";
                five="D";
                ten="M";
            }
            if(i==4)
                one="M";

            if(num%10==4)
            {
                s=s+five+one;
            }
            if(num%10==9)
            {
                s=s+ten+one;
            }
            if(num%10<4)
            {
                for(int j=0;j!=num%10;++j)
                    s=s+one;
            }
            if(num%10>=5 && num%10<9)
            {
                for(int j=0;j!=num%10-5;++j)
                    s=s+one;
                s=s+five;
            }

            num/=10;
            ++i;
        }

        return s.assign(s.rbegin(),s.rend());
    }
};


class Solution3 {
public:
    string intToRoman(int num) {
        string res = "";
        vector<string> v1{"", "M", "MM", "MMM"};
        vector<string> v2{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> v3{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> v4{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return v1[num / 1000] + v2[(num % 1000) / 100] + v3[(num % 100) / 10] + v4[num % 10];
    }
};

class Solution {
public:
    string intToRoman(int num) {
        string res="";
        string arr1[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int arr2[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for(int i=0;i<13;i++){
            while(num>=arr2[i]){
                res+=arr1[i];
                num-=arr2[i];
            }
        }
        return res;
    }
};

int main0825()
{
    Solution n;
    int a=1864;
    cout<<n.intToRoman(a)<<endl;
    Solution2 n2;
    cout<<n2.intToRoman(a)<<endl;
    return 0;
}

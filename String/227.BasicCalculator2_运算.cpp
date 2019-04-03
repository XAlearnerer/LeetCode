//
// Created by zhao on 19-4-3.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> sta;
        int number=0;
        char sym='+';
        for(int i=0;i!=s.length();++i)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                number=number*10+ (s[i]-'0');
            }
            if(s[i]!=' ' && (s[i]<'0' || s[i]>'9') || i==s.length()-1)
            {
                if(sym=='+')
                    sta.push(number);
                else if(sym=='-')
                    sta.push(-number);
                else if(sym=='*')
                {
                    int t=sta.top();
                    sta.pop();
                    sta.push(t*number);
                }
                else
                {
                    int t=sta.top();
                    sta.pop();
                    sta.push(t/number);
                }
                sym=s[i];
                number=0;
            }
        }

        int res=0;
        int size=sta.size();
        for(int i=0;i!=size;++i) {
            res += sta.top();
            sta.pop();
        }
        return res;

    }
};

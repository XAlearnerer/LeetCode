//
// Created by zhao on 18-11-30.
//

#include <iostream>
#include <stack>
using  namespace std;


class Solution2 {    // 不能解   string s="()(()"
public:
    int longestValidParentheses(string s) {
        stack<char> sta;
        int maxlen=0,curlen=0;
        for(int i=0;i!=s.length();++i)
        {
            if(s[i]=='(')
                sta.push(s[i]);
            else
            {
                if(!sta.empty()) {
                    if (sta.top() == '(' && s[i] == ')') {
                        sta.pop();
                        curlen += 2;
                    } else {
                        if (curlen > maxlen)
                            maxlen = curlen;
                        curlen = 0;
                    }
                }
                else{
                    if (curlen > maxlen)
                        maxlen = curlen;
                    curlen = 0;
                }
            }
        }
        if(curlen>maxlen)
            maxlen=curlen;
        return maxlen;
    }
};



class Solution3 {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0;
        stack<int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') m.push(i);
            else if (s[i] == ')') {
                if (m.empty()) start = i + 1;
                else {
                    m.pop();
                    res = m.empty() ? max(res, i - start + 1) : max(res, i - m.top());
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> t;
        int maxlen=0;
        int start=0;
        for(int i=0;i!=s.length();++i)
        {
            if(s[i]=='(')
                t.push(i);
            else
            {
                if(t.empty()) start=i+1;
                else
                {
                    t.pop();
                    maxlen=t.empty()? max(maxlen, i - start + 1) : max(maxlen, i - t.top());
                }
            }
        }
        return maxlen;
    }
};


int main2229()
{
    string s="(()";
    Solution n;
    cout<<n.longestValidParentheses(s)<<endl;
    return 0;
}
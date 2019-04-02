//
// Created by zhao on 19-4-2.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution2 {
public:
    string reverseWords(string s) {
        if(s.empty()) return "";
        vector<string> v;
        string res="";
        int b=0,e=0;
        while(e<s.length()) {
            while (s[b] == ' ') {
                if (b == s.length() - 1)
                    break;
                ++b;
            }
            if (b == s.length() - 1 && s[b] == ' ')
                break;
            e = b;
            while (s[e] != ' ') {
                ++e;
                if (e >= s.length() - 1) {
                    //++e;
                    break;
                }
            }
            cout << b << "--" << e << endl;
            if (s[e] != ' ' && e == s.length() - 1)
            {
                v.push_back(s.substr(b, e - b + 1));
                ++e;
            }
            else
                v.push_back(s.substr(b,e-b));
            cout<<v.back()<<endl;
            b=e;

        }

        for(int i=v.size()-1;i>=0;--i)
        {
            if(i!=0)
                res=res+v[i]+" ";
            else
                res+=v[i];
        }
        return res;

    }
};


class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return "";
        vector<string> v;
        string res="";
        string word;
        for(auto a:s)
        {
            if(a==' ' && word.length()>0)
            {
                v.push_back(word);
                word="";
            }
            else if(a!=' ')
            {
                word+=a;
            }
        }
        if(word.length()>0)
            v.push_back(word);


        for(int i=v.size()-1;i>=0;--i)
        {
            if(i!=0)
                res=res+v[i]+" ";
            else
                res+=v[i];
        }
        return res;

    }
};


//int main()
//{
//    string s="  hello world! ";
//    Solution n;
//    cout<<n.reverseWords(s)<<endl;
//    return 0;
//
//}


//
// Created by zhao on 18-11-13.
//

#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
using  namespace std;

class Solution2 {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.length()>12)return {};
        vector<string> res;
        process(s,"",0,res);
        return res;

    }

    void process(string s,string out,int k,vector<string>& res)
    {
        if(k==4 && s.empty()) {
            cout<<out<<endl;
            res.push_back(out);
        }
        else
        {
            for(int i=1;i!=4;++i)
            {
                if(s.size()<i) break;
                int val=atoi(s.substr(0,i).c_str());
                if(val<=255 && i==to_string(val).length())
                    process(s.substr(i),out+s.substr(0,i)+(k==3?"":"."),k+1,res);
            }
        }
    }

};

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.length()>12)return {};
        vector<string> res;
        for (int a = 1; a < 4; ++a)
            for (int b = 1; b < 4; ++b)
                for (int c = 1; c < 4; ++c)
                    for (int d = 1; d < 4; ++d)
                        if (a + b + c + d == s.size()) {
                            int A = stoi(s.substr(0, a));
                            int B = stoi(s.substr(a, b));
                            int C = stoi(s.substr(a + b, c));
                            int D = stoi(s.substr(a + b + c, d));
                            if(A<=255 && B<=255 && C<=255 & D<=255)
                            {
                                string t = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                                if(t.length()==s.length()+3)
                                {
                                    res.push_back(t);
                                }
                            }
                        }
         return res;
    }
};


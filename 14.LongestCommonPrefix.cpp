//
// Created by zhao on 18-10-19.
//
#include <iostream>
#include <vector>
#include<string>

using namespace std;

// 在vector中找到最短的string开始可能会更好一些
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        if(strs.empty())
            return "";
        if(strs.size()==1)
            return strs[0];

        int i = 0;
        while (i != strs[0].length() && i != strs[1].length()) {
            if (strs[0][i] == strs[1][i]) {
                s += strs[0][i];
                ++i;
            } else
                break;
        }

        if(strs.size()==2)
            return s;

        for (int j = 2; j != strs.size(); ++j)
        {
            if(strs[j].length()<s.length()) s.resize(strs[j].length());
            int k=0;
            while(k!=strs[j].length() && k!=s.length())
            {
                if(strs[j][k]==s[k]) ++k;
                else
                {
                    s.resize(k);
                    break;
                }
            }

        }
        return s;

    }
};


int main1121()
{
    vector<string> v={"ac","ac","","a"};
    Solution n;
    cout<<n.longestCommonPrefix(v)<<endl;

    return 0;
}

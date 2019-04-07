//
// Created by zhao on 19-4-7.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//我们要明确的是，如果不用记忆数组做减少重复计算的优化，那么递归方法跟brute force没什么区别，
//大概率无法通过OJ。所以我们要避免重复计算，如何避免呢，还是看上面的分析，
//如果当s变成 "sanddog"的时候，那么此时我们知道其可以拆分成sand和dog，
//当某个时候如果我们又遇到了这个 "sanddog"的时候，
//我们难道还需要再调用递归算一遍吗，当然不希望啦，所以我们要将这个中间结果保存起来，
//由于我们必须要同时保存s和其所有的拆分的字符串，那么可以使用一个HashMap，来建立二者之间的映射，




class Solution {
public:
    unordered_map<string,vector<string>> m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res=helper(s,wordDict);

        return res;
    }

    vector<string> helper(string s, vector<string>& wordDict)
    {
        if(m.count(s)!=0)
        {
            return m[s];
        }
        if(s.empty()) return {""};
        vector<string> res;
        for(string a:wordDict)
        {
            if(s.substr(0,a.size())!=a) continue;
            vector<string> r=helper(s.substr(a.size()),wordDict);
            //res.insert(res.end(),r.begin(),r.end());
            for(int i=0;i<r.size();++i){
                if(r[i]=="")
                    res.push_back(a + r[i]);
                else
                    res.push_back(a+" "+r[i]);
            }
        }

        m[s]=res;
        return res;
    }
};
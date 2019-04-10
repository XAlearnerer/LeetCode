//
// Created by zhao on 19-4-10.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto a:s)
            ++m[a];
        priority_queue<pair<int,char>> q;
        for(auto a:m)
            q.push({a.second,a.first});

        string res;
        while(!q.empty())
        {
//            char t=q.top().second;
//            int n=q.top().first;
//            for(int i=0;i!=n;++i)
//                res+=t;
            auto t=q.top();
            res.append(t.first, t.second);
            q.pop();
        }

        return res;
    }
};


//
// Created by zhao on 19-5-26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <map>

using namespace std;

class Solution1051 {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> res(heights.begin(),heights.end());
        sort(res.begin(),res.end());
        int q=0;
        for(int i=0;i<heights.size();++i)
        {
            if(heights[i]!=res[i]) ++q;
        }
        return q;
    }
};

/////////////////////////////////////////////////////////////////


class Solution1052_TimeLimitExceeded
        /////////////////   Time Limit Exceeded
        {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        unordered_map<int,int> m;
        int res=0;
        vector<int> vis;
        for(int i=0;i<customers.size();++i)
        {
            if(grumpy[i]==0) res+=customers[i];
            else {
                m[i] = customers[i];
                vis.push_back(i);

            }
        }

        int glo=0;
        for(int i=0;i<vis.size();++i)
        {
            int cur=m[vis[i]];
            for(int j=i+1;j<vis.size();++j)
            {
                if(vis[j]-vis[i]< X) cur+=m[vis[j]];
                else break;
            }
            glo=max(glo,cur);
        }
        return glo+res;
    }
};




class Solution_1052_2 {/////////////////   Time Limit Exceeded
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        unordered_map<int,int> m;
        int res=0;
        vector<int> vis;

        int glo=0;
        for(int i=0;i<customers.size();++i)
        {
            if(grumpy[i]==0) res+=customers[i];
            else {
                m[i] = customers[i];
                vis.push_back(i);

                int cur=0;
                for(int j=vis.size()-1;j>=0;--j)
                {
                    if(vis.back()-vis[j]<X)  cur+=m[vis[j]];
                    else break;
                }
                glo=max(glo,cur);

            }
        }
        return glo+res;
    }
};


class Solution1052{
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        //unordered_map<int,int> m;
        int res=0;
        vector<int> vis;

        int glo=0;
        for(int i=0;i<customers.size();++i)
        {
            if(grumpy[i]==0) res+=customers[i];
            else {
                //m[i] = customers[i];
                vis.push_back(i);

                int cur=0;
                for(int j=vis.size()-1;j>=0;--j)
                {
                    if(vis.back()-vis[j]<X)  cur+=customers[vis[j]];
                    else break;
                }
                glo=max(glo,cur);

            }
        }
        return glo+res;
    }
};

/////////////////////////////////////////////////////////////////


class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {


    }
};














/////////////////////////////////////////////////////////////////


class Solution1054 {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>> q;
        for(auto i:barcodes) ++m[i];
        for(auto i:m) q.push({i.second,i.first});
        vector<int> res;
        while (q.size() >= 2) {
            auto t1 = q.top(); q.pop();
            auto t2 = q.top(); q.pop();
            res.push_back(t1.second);
            res.push_back(t2.second);
            if (--t1.first > 0) q.push(t1);
            if (--t2.first > 0) q.push(t2);
        }
        if (q.size() > 0) res.push_back(q.top().second);


        return res;
    }
};
//
// Created by zhao on 19-5-16.
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
#include <limits.h>

using namespace std;


///////////////////////////////////////////////////////////////////////

class Solution788 {
public:
    int rotatedDigits(int N) {
        int res=0;
        for(int i=1;i<=N;++i)
        {
            if(check(i)) ++res;
        }
        return res;
    }

    bool check(int cur)
    {
        bool f=false;
        string s=to_string(cur);
        for(auto i:s)
        {
            if(i=='3' || i=='4' || i=='7') return false;
            if(i=='2' || i=='5' || i=='6' || i=='9') f=true;  /// cannot return true;   933
        }
        return f;
    }
};

////////////////////////////////////////////////////////////////////////

//实际上这道题就是要求出小人到目标点的最短距离，注意这里的距离不是两点之间的Euclidean距离，
//而应该是曼哈顿距离，即横纵坐标分别求差的绝对值再相加。求出小人到目标点到最短距离后，
//我们还要求每个鬼魂到目标点的最短距离，如果有一个鬼魂到目标带你的最短距离小于等于小人到目标点到最短距的话，
//那么就返回false，否则返回true，



class Solution789 {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis=len(target,{0,0});
        for(auto i:ghosts)
        {
            int m=len(i,target);
            if(m<dis) return false;
        }

        return true;
    }

    int len(vector<int> a,vector<int> b)
    {
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
};



/////////////////////////////////////////////////////////////////////////



class Solution790 {
public:
    int numTilings(int N) {
        int md=1e9;
        md+=7;

        ///////////  %1e9+7

        vector<long long> v(1001,0);
        v[1]=1;
        v[2]=2;
        v[3]=5;
        if(N<=3)
            return v[N];
        for(int i=4;i<=N;++i){
            v[i]=2*v[i-1]+v[i-3];
            v[i]%=md;
        }
        return v[N];

    }
};


/////////////////////////////////////////////////////////////////////////


class Solution791 {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> m;
        for(auto i:T) ++m[i];
        string res;
        for(auto i:S)
        {
            while(m[i]>0)
            {
                --m[i];
                res+=i;
            }
            m.erase(i);
        }
        for(auto i:m)
        {
            while(i.second>0) {
                res += i.first;
                --i.second;
            }
        }

        return res;
    }
};











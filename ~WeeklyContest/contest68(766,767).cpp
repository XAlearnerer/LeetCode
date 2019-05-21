//
// Created by zhao on 19-5-21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <queue>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;


class Solution766 {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        if(n==1 || m==1) return true;
        for(int i=0;i<n-1;++i)
        {
            int j=i,k=0;
            while(j<n-1 && k<m-1)
            {
                if(matrix[j][k]!=matrix[j+1][k+1]) return false;
                ++j;++k;
            }
        }

        for(int i=1;i<m-1;++i)
        {
            int j=i,k=0;
            while(j<m-1 && k<n-1)
            {
                if(matrix[k][j]!=matrix[k+1][j+1]) return false;
                ++j;++k;
            }
        }

        return true;
    }
};

////////////////////////////////////////////////////////////////////////////////



//class Solution {
//public:
//    string reorganizeString(string S) {
//        vector<int> v(26);
//        int m=v[0],mi=0;
//        for(int i=0;i<S.size();++i) {
//            ++v[S[i] - 'a'];
//        }
//
//        for(int i=0;i<26;++i)
//        {
//            if(m<v[i])
//            {
//                m=v[i]; mi=i;
//            }
//        }
//
//        if(m>S.size()+1/2) return "";
//
//        string res;
//        char mostch=mi+'a';
//        int itsfre=v[mi];
//        v[mi]=0;
//        bool f= false;
//        for(int i=0;i<26;++i)
//        {
//            if(v[i]<=0) continue;
//
//            res+=mostch;
//            --itsfre;
//            res+=i+'a';
//            --v[i];
//
//            if(itsfre==0) f=true;
//        }
//        if(f) {}
//        else
//
//
//        return res;
//    }
//};

class Solution767 {
public:
    string reorganizeString(string S) {
        string res = "";
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        for (char c : S) ++m[c];
        for (auto a : m) {
            if (a.second > (S.size() + 1) / 2) return "";
            q.push({a.second, a.first});
        }
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

//接下来，我们每次从优先队列中取队首的两个映射对儿处理，
//因为我们要拆开相同的字母，这两个映射对儿肯定是不同的字母，
//我们可以将其放在一起，之后我们需要将两个映射对儿中的次数自减1，
//如果还有多余的字母，即减1后的次数仍大于0的话，将其再放回最大堆。
//由于我们是两个两个取的，所以最后while循环退出后，
//有可能优先队列中还剩下了一个映射对儿，此时将其加入结果res即可。
//而且这个多余的映射对儿一定只有一个字母了，
//因为我们提前判断过各个字母的出现次数是否小于等于总长度的一半，
//按这种机制来取字母，不可能会剩下多余一个的相同的字母






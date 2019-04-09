//
// Created by zhao on 19-4-8.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


//runtime error: signed integer overflow: 2147483647 + 2 cannot be represented in type 'int' (solution.cpp)
//[[1,2,1],[2147483646,2147483647,2147483647]]

class Solution2 {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty()) return {};
        if(buildings.size()==1)
            return {{buildings[0][0],buildings[0][2]},{buildings[0][2],0}};

        int width=buildings.back()[1];

        vector<int> v(width+2,0);
        for(int i=0;i!=buildings.size();++i)
        {
            for(int j=buildings[i][0];j!=buildings[i][1];++j)
            {
                v[j]=max(v[j],buildings[i][2]);
            }
        }

        vector<pair<int,int>> res;
        int change=0;
        for(int i=0;i!=v.size();++i)
        {
            if(v[i]!=change)
            {
                res.push_back({i,v[i]});
                change=v[i];
            }
        }

        return res;
    }
};

//int main()
//{
//    vector<vector<int> > b={{0,2147483647,2147483647}};
//    Solution n;
//    n.getSkyline(b);
//    return 0;
//
//}

#include <set>

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> v,res;
        multiset<int> set;
        for(int i=0;i!=buildings.size();++i)
        {
            v.push_back({buildings[i][0],-buildings[i][2]});
            v.push_back({buildings[i][1],buildings[i][2]});
        }

        //sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){ return a.first<b.first;});
        sort(v.begin(),v.end());  /////这里 pair的默认排序应该是 first先，若first大小一致，则按second排序


        int cur=0,pre=0;
        set.insert(0);

        for(int i=0;i<v.size();++i)
        {
            if(v[i].second<0) set.insert(-v[i].second);
            else
                set.erase(set.find(v[i].second));

            for(auto a:set)
                cout<<a<<" ";
            cout<<endl;

            cur= *set.rbegin();
            if(cur!=pre)
            {
                res.push_back({v[i].first,cur});
                pre=cur;
            }
        }

        return res;
    }
};

//class Solution3 {
//public:
//    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
//        vector<pair<int, int>> h, res;
//        multiset<int> m;
//        int pre = 0, cur = 0;
//        for (auto &a : buildings) {
//            h.push_back({a[0], -a[2]});
//            h.push_back({a[1], a[2]});
//        }
//        sort(h.begin(), h.end());
//        m.insert(0);
//        for (auto &a : h) {
//            if (a.second < 0) m.insert(-a.second);
//            else m.erase(m.find(a.second));
//
//            for(auto a:m)
//                cout<<a<<" ";
//            cout<<endl;
//
//            cur = *m.rbegin();
//            if (cur != pre) {
//                res.push_back({a.first, cur});
//                pre = cur;
//            }
//        }
//        return res;
//    }
//};

//int main()
//{
//    vector<vector<int>> buildings={{0,2,3},{2,5,3}};
//    Solution n;
//    n.getSkyline(buildings);
//
//    return 0;
//}
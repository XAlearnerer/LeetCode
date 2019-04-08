//
// Created by zhao on 19-4-8.
//

#include <iostream>
#include <vector>
#include <algorithm>
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



class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {



    }
};
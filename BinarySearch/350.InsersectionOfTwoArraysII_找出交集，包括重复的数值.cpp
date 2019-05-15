//
// Created by zhao on 19-5-15.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(auto i:nums1) ++m[i];
        vector<int> res;
        for(auto j:nums2)
        {
//            if(m.count(j)>0)
//            {
//                --m[j];
//                res.push_back(j);
//            }

            if(m[j]>0)
            {
                --m[j];
                res.push_back(j);
            }
        }
        return res;
    }
};
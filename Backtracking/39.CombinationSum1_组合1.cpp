//
// Created by zhao on 19-4-6.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> combin;
        vector<int> comnow;
        backtracking(combin,comnow,candidates,target,0);
        return combin;

    }

     void backtracking(vector<vector<int>>& combin,vector<int>& comnow,vector<int>& candidates,int target,int now)
     {
        if(target==0)
        {
            combin.push_back(comnow);
        }
        else
        {
            for(int i=now; i!=candidates.size(); ++i)
            {
                if(target >= candidates[i])
                {
                    comnow.push_back(candidates[i]);
                    backtracking(combin,comnow,candidates,target-candidates[i],i);
                    comnow.pop_back();
                }
            }
        }
     }
};



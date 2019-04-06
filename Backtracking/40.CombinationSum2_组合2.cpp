//
// Created by zhao on 19-4-6.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> com;
        backtracking(res,candidates,com,target,0);
        return res;
    }

    void backtracking(vector<vector<int>>& res,vector<int>& candidates,vector<int>& com,int target,int now)
    {
        if(target==0)
            res.push_back(com);
        else
        {
            for(int i=now;i!=candidates.size();++i)
            {

                if(target>=candidates[i])
                {
                    if(i>now&&candidates[i]==candidates[i-1])
                        continue;
                    com.push_back(candidates[i]);
                    backtracking(res,candidates,com,target-candidates[i],i + 1);
                    com.pop_back();
                }
            }
        }
    }
};
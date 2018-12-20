//
// Created by zhao on 18-10-25.
//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution2 {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res,
            std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            //combination.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<std::vector<int> > res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }

    void combinationSum(vector<int> &candidates, int target, vector<std::vector<int> > &res,
                        vector<int> &combination, int begin)
    {
        if(!target) {
            res.push_back(combination);
            return;
        }

		for (int i = begin; i != candidates.size(); ++i)
        {
			if (target >= candidates[i])
            {
                combination.push_back(candidates[i]);
				combinationSum(candidates, target - candidates[i], res, combination, i);
                combination.pop_back();
            }

        }

    }
};

int main1721()
{
    vector<int> v1={2,3,5};
    Solution n;
    vector<vector<int> >vv=n.combinationSum(v1,8);
    for(auto i:vv) {
		for (auto j : i)
            cout << j << " ";
        cout<<endl;
    }

    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> res;
		vector<int> cur;
		helper(candidates, target, res, cur, 0);
		return res;
	}

	void helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& cur, int be)
	{
		if (target == 0)
		{
			res.push_back(cur);
			return;
		}

		for (int i = be; i < candidates.size(); ++i)
		{
			if (target < candidates[i]) break;
			cur.push_back(candidates[i]);
			helper(candidates, target - candidates[i], res, cur, i);
			cur.pop_back();
		}
	}
};


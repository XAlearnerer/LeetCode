#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<std::vector<int> > res;
		vector<int> combination;
		combinationSum_2(candidates, target, res, combination, 0);
		return res;
	}

	void combinationSum_2(vector<int> &candidates, int target, vector<std::vector<int> > &res,
		vector<int> &combination, int begin)
	{
		if(!target)
		{
			res.push_back(combination);
			return;
		}
		for (int i = begin; i != candidates.size(); ++i)
		{
			if (target >= candidates[i])
			{
				if (i > begin && candidates[i] == candidates[i - 1]) 
					continue;
				combination.push_back(candidates[i]);
				combinationSum_2(candidates, target - candidates[i], res, combination, i + 1);
				combination.pop_back();
			}
		}
	}

};



int main()
{
	vector<int> v1 = { 2,5,2,1,2 };
	Solution n;
	vector<vector<int> >vv = n.combinationSum2(v1, 5);
	for (auto i : vv) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}
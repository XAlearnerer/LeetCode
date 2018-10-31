#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (k > n || k < 0) return {};
		if (k == 0) return { {} };
		vector<vector<int>> res;
		vector<int> combination;
		//Kcombine(res, combination, 1, k, n);
		Kcombine_2(res, combination, 1, k, n);
		return res;
	}
	void Kcombine(vector<vector<int>> &res, vector<int> &combination, int begin, int k, int n)
	{
		if (combination.size() == k)
		{
			res.push_back(combination);
			return;
		}

		for (int i = begin; i <= n - (k - combination.size()) + 1; i++) //剪枝
		//for (int i = begin; i <= n; ++i)
		{
			combination.push_back(i);
			Kcombine(res, combination, i + 1, k, n);
			combination.pop_back();
		}
	}

	void Kcombine_2(vector<vector<int>> &res, vector<int> &combination, int begin, int k, int n)
	{
		if (!k)
		{
			res.push_back(combination);
			return;
		}
		for (int i = begin; n - i + 1 >= k; ++i)
		{
			combination.push_back(i);
			Kcombine_2(res, combination, i + 1, k - 1, n);
			combination.pop_back();
		}
	}
};


int main1632()
{
	Solution n;
	vector<vector<int> >vv = n.combine(4, 2);
	for (auto i : vv) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}


	return 0;
}
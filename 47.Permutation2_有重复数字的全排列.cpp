#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int> >res;
		sort(nums.begin(), nums.end());
		Per(res, 0, nums);
		return res;
	}
	void Per(vector<vector<int> > &res, int begin, vector<int> nums)
	{
		if (begin == nums.size() - 1)
		{
			res.push_back(nums);
			return;
		}
		for (int i = begin; i != nums.size(); ++i)
		{
			if (i == begin || nums[begin] != nums[i])
			{
				swap(nums[begin], nums[i]);
				Per(res, begin + 1, nums);
				//swap(nums[begin], nums[i]);
			}
		}
	}

};

int main1553()
{
	vector<int> v1 = { 1,1,2 };
	Solution n;
	vector<vector<int> >vv = n.permuteUnique(v1);
	for (auto i : vv) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int> >res;
		Per(res,0, nums);
		return res;
	}
	void Per(vector<vector<int> > &res,int begin, vector<int> nums)
	{
		if (begin == nums.size())
		{
			res.push_back(nums);
			return;
		}

		for (int i = begin; i != nums.size(); ++i)
		{
			swap(nums[begin], nums[i]);
			Per(res ,begin + 1, nums);
			//swap(nums[begin], nums[i]);
		}
	}
};

class Solution2 {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int> >res;
		vector<int> com;
		Per(res, com, nums);
		return res;
	}
	void Per(vector<vector<int> > &res, vector<int>& com, vector<int> nums)
	{
		if (com.size() == nums.size())
		{
			res.push_back(com);
			return;
		}

		bool repeat = false;
		for (int i = 0; i != nums.size(); ++i)
		{
			for (int j = 0; j != com.size(); ++j)
			{
				if (com[j] == nums[i])
					repeat = true;
			}

			if (repeat)
			{
				repeat = false;
				continue;
			}

			com.push_back(nums[i]);
			Per(res, com, nums);
			com.pop_back();
		}
	}
};

int main1043()
{
	vector<int> v1 = { 1,2,3 ,4};
	Solution n;
	vector<vector<int> >vv = n.permute(v1);
	for (auto i : vv) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}


#include<iostream>
#include<vector>
using namespace std;
#include<map>
#include<algorithm>

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(),nums.end());

		int vlength = nums.size();
		for (int begin = 0; begin < vlength - 2; ++begin)
		{
			//process(begin, nums);
			while (begin > 0 && nums[begin] == nums[begin - 1])
				++begin;

			int TheSum = -nums[begin];
			int i = begin + 1, j = nums.size() - 1;
			while (i < j)
			{
				if (nums[i] + nums[j] == TheSum)
				{
					vector<int> v = { nums[begin],nums[i],nums[j] };
					++i;
					--j;
					/*if (find(vv.begin(), vv.end(), v) == vv.end())*/
					vv.push_back(v);

					while (i < j && nums[i] == nums[i - 1])
						++i;
					while (i < j && nums[j] == nums[j + 1])
						--j;
					

				}
				else if (nums[i] + nums[j] < TheSum)
					++i;
				else
					--j;
			}

		}
		return vv;
	}

	//void process(int begin, vector<int> nums)
	//{
	//	int TheSum = -nums[begin];
	//	int i = begin + 1, j = nums.size() - 1;
	//	while (i < j)
	//	{
	//		if (nums[i] + nums[j] == TheSum)
	//		{
	//			vector<int> v = { nums[begin],nums[i],nums[j] };
	//			++i;
	//			--j;
	//			/*if (find(vv.begin(), vv.end(), v) == vv.end())*/
	//			while (i < j && nums[i] == nums[i - 1])
	//				++i;
	//			while (i < j && nums[j] == nums[j + 1])
	//				--j;
	//			vv.push_back(v);
	//			
	//		}
	//		else if (nums[i] + nums[j] < TheSum)
	//			++i;
	//		else
	//			--j;
	//	}
	//}

private:
	vector<vector<int>> vv;
};


int main1709()
{
	vector<int> v = { -1, 0, 1, 2, -1, -4 };
	Solution n;
	vector<vector<int>> vv = n.threeSum(v);
	for (int i = 0; i != vv.size(); ++i)
	{
		vector<int> v = vv[i];
		for (auto j : v)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 1)
			//return (nums[0] == target) ? {0, 0} : {-1, -1};
			if (nums[0] == target)
				return{ 0,0 };
			else return{ -1,-1 };

		int i = 0, j = nums.size() - 1;
		while (i <= j)
		{
			int mid = (i + j) / 2;
			if (nums[mid] == target) 
			{
				int n = mid, m = mid;
				while (n - 1 >= 0 && nums[n - 1] == nums[mid])--n;
				while (m + 1 < nums.size() && nums[m + 1] == nums[mid])++m;
				return { n,m };
			}
			else if (nums[mid] > target)
			{
				j = mid - 1;
			}
			else
			{
				i = mid + 1;
			}
		}

		return { -1,-1 };

	}
};


int main1646()
{
	vector<int> v = {1,1,2};
	int target = 1;
	Solution n;
	vector<int> m = n.searchRange(v, target);
	for (auto a : m)
		cout << a << endl;
	return 0;
}
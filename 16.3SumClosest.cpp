#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
#include<math.h>

class Solution {
public:
	int closestgap, closestnums;
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		//closestgap = nums[0] + nums[1] + nums[2] - target;
		//closestnums = nums[0] + nums[1] + nums[2];
		closestgap = INT_MAX;
		closestnums = INT_MAX;
		int vlength = nums.size();
		for (int begin = 0; begin < vlength - 2; ++begin)
		{
			int i = begin + 1, j = vlength - 1;
			while (i < j)
			{
				int num = nums[j] + nums[i] + nums[begin];
				int gap = abs(target - num);
				if (gap < abs(closestgap))
				{
					closestgap = gap;
					closestnums = num;
				}

				if (num < target)
					++i;
				else
					--j;
			}

		}

		return closestnums;

	}
};




int main1008()
{
	vector<int> v = { -1, 2, 1, -4 };
	int target = 1;

	Solution n;
	cout << n.threeSumClosest(v, target) << endl;

	return 0;
}
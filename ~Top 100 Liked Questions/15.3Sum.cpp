#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3) return {};
		sort(nums.begin(), nums.end());
		if (nums[0] > 0 || nums.back() < 0) return {};
		vector<vector<int>> res;
		for (int i = 0; i < nums.size() - 2; ++i)
		{

			//////////////////////////////

			if (nums[i] > 0) break;

			//////////////////////////////

			int j = i + 1, k = nums.size() - 1;


			//while (i > 0 && nums[i] == nums[i - 1]) ++i;
			if (i > 0 && nums[i] == nums[i - 1]) continue;


			while (j < k)
			{
				if (nums[i] + nums[j] + nums[k] == 0)
				{
					res.push_back({ nums[i] , nums[j] , nums[k] });
					while (j < k && nums[j] == nums[j + 1]) ++j;
					while (j < k && nums[k] == nums[k - 1]) --k;
					++j, --k;
				}
				else if (nums[i] + nums[j] + nums[k] < 0) ++j;
				else --k;
			}
		}

		return res;
	}
};



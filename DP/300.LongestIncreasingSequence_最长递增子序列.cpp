#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


///////////// dp /////////////////

class Solution2 {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		int res = 0;
		vector<int> dp(nums.size(), 1);
		for (int i = 0; i != nums.size(); ++i)
		{
			for (int j = 0; j != i; ++j)
			{
				if (nums[i] > nums[j])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}

			res = max(res, dp[i]);
		}

		//for (auto i : dp)
		//	cout << i << " ";
		//cout << endl;

		return res;
	}
};



/////////////// STL /////////////////////

//lower_bound返回数组中第一个不小于指定值的元素，跟上面的算法类似，
//我们还需要一个一维数组v，然后对于遍历到的nums中每一个元素，
//找其lower_bound，如果没有lower_bound，说明新元素比一维数组的尾元素还要大，
//直接添加到数组v中，跟解法二的思路相同了。如果有lower_bound，
//说明新元素不是最大的，将其lower_bound替换为新元素，
//这个过程跟算法二的二分查找法的部分实现相同功能，
//最后也是返回数组v的长度


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> res;
		for (int i = 0; i != nums.size(); ++i)
		{
			auto it = lower_bound(res.begin(), res.end(), nums[i]);
			if (it == res.end()) res.push_back(nums[i]);
			else *it = nums[i];
		}

		return res.size();
	}
};



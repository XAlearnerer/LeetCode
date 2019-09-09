#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


// 思路是先建立一个空的 dp 数组，然后开始遍历原数组，
// 对于每一个遍历到的数字，用二分查找法在 dp 数组找第一个不小于它的数字，
// 如果这个数字不存在，那么直接在 dp 数组后面加上遍历到的数字，
// 如果存在，则将这个数字更新为当前遍历到的数字，最后返回 dp 数组的长度即可，
// 注意的是，跟上面的方法一样，
// 特别注意的是 dp 数组的值可能不是一个真实的 LIS。
// 参见代码如下：


class Solution2 {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp;
		for (int i = 0; i < nums.size(); ++i) {
			int left = 0, right = dp.size();
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (dp[mid] < nums[i]) left = mid + 1;
				else right = mid;
			}
			if (right >= dp.size()) dp.push_back(nums[i]);
			else dp[right] = nums[i];
		}


		for (auto i : dp)
			cout << i << " ";
		cout << endl;

		return dp.size();
	}
};


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> v;
		for (int i = 0; i < nums.size(); ++i)
		{
			auto it = lower_bound(v.begin(), v.end(), nums[i]);
			if (it == v.end()) v.push_back(nums[i]);
			else *it = nums[i];
		}
		return v.size();
	}
};






//int main()
//{
//	vector<int> v = { 69079936, 236011312, 77957850, 653604087, 443890802, 277126428, 755625552,
//		768751840, 993860213 ,882053548 };
//	Solution n;
//	cout << n.lengthOfLIS(v) << endl;
//
//	return 0;
//}


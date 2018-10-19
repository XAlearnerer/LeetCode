#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
#include<math.h>
#include<set>


class Solution {
public:
	vector<vector<int>> vv;
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int vlength = nums.size();
		for (int begin = 0; begin < vlength - 3; ++begin)
		{
			while (begin > 0 && nums[begin] == nums[begin - 1])
				continue;
			int i = begin + 1;
			while (i < vlength - 2)
			{
				int j = i + 1, k = vlength - 1;
				while (j < k)
				{
					if (nums[begin] + nums[i] + nums[j] + nums[k] == target)
					{
						vector<int> v = { nums[begin],nums[i],nums[j],nums[k] };
						vv.push_back(v);
						++j;
						--k;

						while (j < k && nums[j] == nums[j - 1]) ++j;
						while (j < k && nums[k] == nums[k + 1]) --k;
					}
					else if (nums[begin] + nums[i] + nums[j] + nums[k] < target)
					{
						++j;
					}
					else
						--k;
				}
				++i;
			}
		}
		return vv;
	}
};


//在这里为了避免重复项，我们使用了STL中的set，
//其特点是不能有重复，如果新加入的数在set中原本就存在的话，插入操作就会失败，
//这样能很好的避免的重复项的存在。此题的O(n ^ 3)解法的思路跟3Sum 三数之和基本没啥区别，
//就是多加了一层for循环，其他的都一样，代码如下：
class Solution2 {
public:
	vector<vector<int>> fourSum(vector<int> &nums, int target) {
		set<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < int(nums.size() - 3); ++i) {
			for (int j = i + 1; j < int(nums.size() - 2); ++j) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int left = j + 1, right = nums.size() - 1;
				while (left < right) {
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						vector<int> out{ nums[i], nums[j], nums[left], nums[right] };
						res.insert(out);
						++left; --right;
					}
					else if (sum < target) ++left;
					else --right;
				}
			}
		}
		return vector<vector<int>>(res.begin(), res.end());
	}
};

int main2039()
{
	vector<int> v = { 1, 0, -1, 0, -2, 2 };
	int target = 0;

	Solution n;
	vector<vector<int>> vv = n.fourSum(v,target);
	for (int i = 0; i != vv.size(); ++i)
	{
		vector<int> v = vv[i];
		for (auto j : v)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}








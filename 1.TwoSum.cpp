#include<iostream>
#include<vector>
using namespace std;
#include<map>


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> m;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (m.count(target - nums[i]))
			{
				return { i, m[target - nums[i]] };
			}
			m[nums[i]] = i;
		}
		return {};
	}
};


int main()
{
	vector<int> v = { 2, 7, 11, 15 };
	int target = 9;
	Solution n;

	vector<int> v2 = n.twoSum(v, target);

	for (auto i : v2)
		cout << i << " ";
	return 0;
}

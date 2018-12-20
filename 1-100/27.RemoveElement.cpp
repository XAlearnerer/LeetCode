#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution2 {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()) return 0;
		int i = 0, j = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val) {
				nums[j] = nums[i];
				j++;
			}
		}

		return j;
	}
};

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		while (1)
		{
			auto it = find(nums.begin(), nums.end(), val);
			if (it == nums.end()) break;

			nums.erase(it);
		}

		return nums.size();
	}
};




int main1718()
{
	Solution n;
	vector<int> v = { 0,1,2,2,3,0,4,2 };
	int m = n.removeElement(v, 2);

	for (int i = 0; i != m; ++i)
		cout << v[i] << endl;
	return 0;
}

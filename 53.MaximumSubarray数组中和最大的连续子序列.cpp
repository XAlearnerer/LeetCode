#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int i = 0, j = 0, cur = nums[0], max = nums[0];
		while (j < nums.size() - 1)
		{
			if (cur < 0)           
			{
				++j;
				i = j;
				cur = nums[i];
			}
			else
			{
				++j;
				cur += nums[j];
			}
			if (max < cur)
				max = cur;
		}
		return max;

	}
};

int main1007()
{
	//vector<int > v = { -2,1 };
	vector<int > v = { 1 };
	Solution n;
	cout << n.maxSubArray(v) << endl;
	return 0;
}
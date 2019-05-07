#include<iostream>
#include<vector>
using namespace std;

class NumArray {
public:
	NumArray(vector<int>& nums) {
		sum.push_back(0);
		int cur = 0;
		for (int i = 0; i != nums.size(); ++i)
		{
			cur += nums[i];
			sum.push_back(cur);
		}
	}

	int sumRange(int i, int j) {
		return sum[j + 1] - sum[i];
	}
	vector<int> sum;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* int param_1 = obj->sumRange(i,j);
*/
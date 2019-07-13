#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> a(n, 1);
		vector<int> b(n, 1);
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			a[i + 1] = a[i] * nums[i];
			b[i + 1] = b[i] * nums[n - 1 - i];
		}


		vector<int> res;
		for (int i = 0; i < n; ++i)
			res.push_back(a[i] * b[n - 1 - i]);

		return res;
	}
};







#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



class Solution_2 {
public:
	bool PredictTheWinner(vector<int>& nums) {
		if (nums.size() == 1) return true;
		if (p1(nums, 0, nums.size() - 1) >= p2(nums, 0, nums.size() - 1)) 
			return true;
		else return false;
	}

	int p1(vector<int>& nums, int i, int j)
	{
		if (i == j) return nums[i];
		return max(nums[i] + p2(nums, i + 1, j), nums[j] + p2(nums, i, j - 1));
	}

	int p2(vector<int>& nums, int i, int j)
	{
		if (i == j) return 0;
		return min(p1(nums, i + 1, j), p1(nums, i, j - 1));
	}

};


/////////////////////////////////////////////////////////////////////////////////




class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		if (nums.size() == 1) return true;
		int n = nums.size();
		vector<vector<int>> f(n, vector<int>(n, 0));
		vector<vector<int>> g(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				f[j][i] = max(nums[i] + g[j][i - 1], nums[j] + g[j + 1][i]);
				g[j][i] = min(f[j + 1][i], f[j][i - 1]);
			}
		}
		return f[0][n - 1] >= g[0][n - 1];
	}
};


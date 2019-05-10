#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


///////////////////// Recursion //////////////////////////

class Solution2 {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) return true;
		return player_1(nums, 0, n - 1) >= player_2(nums, 0, n - 1);
	}

	int player_1(vector<int>& nums, int i, int j)
	{
		if (i == j) return nums[i];
		return max(nums[i] + player_2(nums, i + 1, j), nums[j] + player_2(nums, i, j - 1));
	}

	int player_2(vector<int>& nums, int i, int j)
	{
		if (i == j) return 0;
		return min(player_1(nums, i + 1, j), player_1(nums, i, j - 1));
	}

};



//////////////////// DP ///////////////////////////

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> dp_1(n, vector<int>(n, 0));
		vector<vector<int>> dp_2(n, vector<int>(n, 0));

		for (int i = 0; i != n; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				dp_1[j][i] = max(nums[i] + dp_2[j][i - 1], nums[j] + dp_2[j + 1][i]);
				dp_2[j][i] = min(dp_1[j + 1][i], dp_1[j][i - 1]);
			}
		}
		return dp_1[0][n - 1] >= dp_2[0][n - 1];

	}
};

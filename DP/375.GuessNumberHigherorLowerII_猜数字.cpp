#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		int local = 0, global = 0;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = i - 1; j > 0; --j)
			{
				global = INT_MAX;
				for (int k = j + 1; k < i; ++k)
				{
					//local = max(dp[i][k - 1], dp[k + 1][j]) + k;
					local = max(dp[j][k - 1], dp[k + 1][i]) + k;
					
					global = min(global, local);
				}
				//if (j + 1 == i) dp[i][j] = j;
				//else dp[i][j] = global;

				if (j + 1 == i) dp[j][i] = j;
				else dp[j][i] = global;
			}
		}
		return dp[1][n];
	}
};


class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		for (int i = 2; i <= n; ++i) {
			for (int j = i - 1; j > 0; --j) {
				int global_min = INT_MAX;
				for (int k = j + 1; k < i; ++k) {
					int local_max = k + max(dp[j][k - 1], dp[k + 1][i]);
					global_min = min(global_min, local_max);
				}
				dp[j][i] = j + 1 == i ? j : global_min;
			}
		}
		return dp[1][n];
	}
};
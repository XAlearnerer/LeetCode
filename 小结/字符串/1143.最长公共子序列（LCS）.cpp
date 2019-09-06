#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int longestCommonSubsequence(string t1, string t2) {
		if (t1.empty() || t2.empty()) return 0;
		int l1 = t1.size(), l2 = t2.size();
		vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
		for (int i = 1; i <= l1; ++i)
		{
			for (int j = 1; j <= l2; ++j)
			{
				if (t1[i - 1] == t2[j - 1])	
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		//for (auto i : dp)
		//{
		//	for (auto j : i)
		//		cout << j << " ";
		//	cout << endl;
		//}


		return dp[l1][l2];
	}
};


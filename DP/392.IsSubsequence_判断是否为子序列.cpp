#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution2 { //ÂýµÄÒªËÀ
public:
	bool isSubsequence(string s, string t) {
		int m = s.size(), n = t.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= n; ++i)
			dp[0][i] = 1;

		bool p = false;
		for (int i = 1; i <= m; ++i)
		{
			p = false;
			for (int j = 1; j <= n; ++j)
			{
				if (p) dp[i][j] = 1;
				if (s[i - 1] == t[j - 1])
				{
					if (dp[i - 1][j - 1] == 1)
					{
						p = true;
						dp[i][j] = 1;
					}
				}
			}
		}


		return dp[m][n];
	}
};



class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s.empty()) return true;
		int m = s.size(), n = t.size();
		int it = 0;
		for (int i = 0; i != n; ++i)
		{
			if (s[it] == t[i]) ++it;
			if (it == m) return true;
		}
		return false;
	}
};


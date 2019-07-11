#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;




class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> t(wordDict.begin(), wordDict.end());

		vector<int> dp(s.size() + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < dp.size(); ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (dp[j] == 1 && t.find(s.substr(j, i - j)) != t.end())
				{
					dp[i] = 1;
					break;
				}
			}
		}

		return dp.back();
	}
};

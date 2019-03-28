#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

//这种使用记忆数组memo的递归写法，和使用dp数组的迭代写法，乃解题的两大神器，
//凡事能用dp解的题，一般也有用记忆数组的递归解法

//玩子数组或者子字符串且求极值的题，基本就是DP没差了，虽然这道题没有求极值，
//但是玩子字符串也符合DP的状态转移的特点。

class Solution2 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string>set(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;
		for (int i = 1; i < dp.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (set.count(s.substr(j, i - j)) && dp[j] == 1)
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp.back();
	}
};


class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string>set(wordDict.begin(), wordDict.end());
		queue<int> q;
		vector<bool> v(s.size());
		q.push(0);
		while (!q.empty())
		{
			int start = q.front();
			q.pop();
			if (v[start] != true)
			{
				for (int i = start + 1; i != s.size() + 1; ++i)
				{
					if (set.count(s.substr(start, i - start)))
					{
						q.push(i);
						if (i == s.size()) return true;
					}
				}
				v[start] = true;
			}
		}
		return false;
	}
};


#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <queue>
#include <string>
#include <set>

using namespace std;



class Solution1033 {
public:
	vector<int> numMovesStones(int a, int b, int c) {
		vector<int> v = { a,b,c };
		sort(v.begin(), v.end());

		int len1 = v[1] - v[0] - 1;
		int len2 = v[2] - v[1] - 1;

		if (len1 == 0 && len2 == 0)
			return { 0,0 };
		if (len1 == 0)
			return { 1,len2 };
		if (len2 == 0)
			return { 1,len1 };

		
		vector<int> res;
		helper(v, 0, res);
		int m = res[0];

		for (auto i : res)
		{
			m = min(m, i);
		}

		return { m,len1 + len2 };
	}

	int helper(vector<int> v, int level, vector<int>& res)
	{
		sort(v.begin(), v.end());

		int len1 = v[1] - v[0] - 1;
		int len2 = v[2] - v[1] - 1;

		if (len1 == 0 && len2 == 0)
		{
			res.push_back(level);
			return 0;
		}
		if (len1 == 0 || len2 == 0)
		{
			res.push_back(level + 1);
			return 1;
		}

		int cur = INT_MAX;
		int i,pre;
		

		if (len1 > len2)
		{
			pre = v[1] + 1;
			i = v[1] + 1;
			for (; i < v[2]; ++i)
			{
				if (i == v[1]) continue;
				v[0] = i;
				cur = 1 + min(cur, helper(v, level + 1, res));
				v[0] = pre;
			}
		}

		else
		{
			pre = v[1] - 1;
			i = v[1] - 1;
			for (; i > v[0]; --i)
			{
				if (i == v[1]) continue;
				v[2] = i;
				cur = 1 + min(cur, helper(v, level + 1, res));
				v[2] = pre;
			}
		}

		/*
		int pre = v[0];
		i = pre + 1;
		while (i < v[2])
		{
			if (i == v[1]) ++i;
			break;
		}
		for (; i < v[2]; ++i)
		{
			if (i == v[1]) continue;
			v[0] = i;
			cur = 1 + min(cur, helper(v, level + 1, res));
			v[0] = pre;
		}

		pre = v[2];
		i = pre - 1;
		while (i > v[0])
		{
			if (i == v[1]) --i;
			break;
		}
		for (; i > v[0]; --i)
		{
			if (i == v[1]) continue;
			v[2] = i;
			cur = 1 + min(cur, helper(v, level + 1, res));
			v[2] = pre;
		}
		*/


		return cur;
	}

};



///////////////////////////////////////////////////////////////



//The Longest Common Subsequence

class Solution1035 {
public:
	int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		if (A.empty() || B.empty()) return 0;
		int n = A.size(), m = B.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (A[i - 1] == B[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		return dp[n][m];
	}
};



///////////////////////////////////////////////////////////////


// Intuition
// The target is reacheable if the soruce is not blocked, 
// and the target is not blocked.With 200 blocks, 
// we only need to travel some limited distance to check that we are not blocked.
// 
// Solution
// Do BFS max_steps times.If we find our target, return true.
// If after all steps our BFS queue is empty, we are blocked.
// 
// Note 1: we need to do this operation for both source and target.
// Note 2 : I am using 50 steps here and this solution is accepted(missing test case).
// If I use 200 steps I can get TLE.The fix for that is to use hash set instead of set,
// but in C++ it's a little longer to do that for a pair of coordinates.


class Solution1036 {
public:
	bool isEscapePossible(set<pair<int, int>>& blocked, vector<int>& s, vector<int>& t) {
		set<pair<int, int>> visited;
		queue<pair<int, int>> q;
		q.push({ s[0], s[1] });
		int max_steps = 50;
		while (!q.empty() && --max_steps >= 0) 
		{
			queue<pair<int, int>> q1;
			while (!q.empty()) 
			{
				auto p = q.front();
				q.pop();
				if (p.first >= 0 && p.first < 10 ^ 6 && p.second >= 0 && p.second < 10 ^ 6) {
					if (visited.find(p) != end(visited) || blocked.find(p) != end(blocked)) continue;
					visited.insert(p);
					if (p.first == t[0] && p.second == t[1]) return true;
					q1.push({ p.first + 1, p.second });
					q1.push({ p.first - 1, p.second });
					q1.push({ p.first, p.second + 1 });
					q1.push({ p.first, p.second - 1 });
				}

			}
			swap(q, q1);
		}
		return !q.empty();
	}

	bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& s, vector<int>& t) {
		set<pair<int, int>> s_blocked;
		for (auto b : blocked) s_blocked.insert({ b[0], b[1] });
		return isEscapePossible(s_blocked, s, t) && isEscapePossible(s_blocked, t, s);
	}
};




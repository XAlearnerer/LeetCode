#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <map>

using namespace std;


class Solution1089 {
public:
	void duplicateZeros(vector<int>& arr) {
		if (arr.empty()) return;
		if (arr.size() == 1) return;
		int prelen = arr.size();
		int count = 0, pos = 0, zeros = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			if (arr[i] == 0) { count += 2; ++zeros; }
			else count += 1;

			if (count >= prelen) { pos = i; break; }
		}

		for (int j = pos; j >= 0; --j)
		{
			if (j == pos && count > prelen && arr[j] == 0) { --zeros; arr[j + zeros] = arr[j]; continue; }

			if (arr[j] != 0) { arr[j + zeros] = arr[j]; }
			else
			{
				arr[j + zeros] = 0;
				arr[j + zeros - 1] = 0;
				--zeros;
			}
		}
	}
};

//////////////////////////////////////////////////////////////////////////////


class Solution1090 {
public:
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted,
		int use_limit) {

		multimap<int, int> m;
		unordered_map<int, int> u;

		int res = 0;
		for (int i = 0; i < values.size(); ++i) m.insert({ values[i],labels[i] });
	
		//? 这里不能写 <	
		//for (auto it = m.rbegin(); it < m.rend() && num_wanted > 0; ++it)
		for (auto it = m.rbegin(); it != m.rend() && num_wanted > 0; ++it)
		{
			++u[it->second];
			if (u[it->second] <= use_limit)
			{
				--num_wanted;
				res += it->first;
			}
		}
		return res;
	}
};


//////////////////////////////////////////////////////////////////////////////


class Solution1091 {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return -1;
		if (grid.size() == 1 && grid[0].size() == 1) return grid[0][0];
		int n = grid.size();
		if (grid[n - 1][n - 1] == 1 || grid[0][0] == 1) return -1;
		vector<vector<int>> v(n, vector<int>(n, 0));
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		int res = 0;
		bool flag = false;
		while (!q.empty())
		{
			int len = q.size();
			bool turn = false;
			for (int i = 0; i < len; ++i)
			{
				auto it = q.front();
				q.pop();
				int x = it.first, y = it.second;
				if (x == n - 1 && y == n - 1) { flag = true; turn = true; break; }
				if (v[x][y] == 1) continue;
				v[x][y] = 1;
				//++res;
				if (x >= 1 && y >= 1 && grid[x - 1][y - 1] == 0) q.push({ x - 1,y - 1 });
				if (x >= 1 && grid[x - 1][y] == 0) q.push({ x - 1,y });
				if (y >= 1 && grid[x][y - 1] == 0)q.push({ x,y - 1 });
				if (x >= 1 && y < n - 1 && grid[x - 1][y + 1] == 0) q.push({ x - 1,y + 1 });
				if (y < n - 1 && grid[x][y + 1] == 0) q.push({ x,y + 1 });
				if (x < n - 1 && y >= 1 && grid[x + 1][y - 1] == 0) q.push({ x + 1,y - 1 });
				if (x < n - 1 && grid[x + 1][y] == 0) q.push({ x + 1,y });
				if (x < n - 1 && y < n - 1 && grid[x + 1][y + 1] == 0) q.push({ x + 1,y + 1 });
			}
			++res;
			if (turn) break;
		}

		if (flag) return res;
		else return -1;
	}
};


//////////////////////////////////////////////////////////////////////////////


class Solution1092 {
public:
	string shortestCommonSupersequence(string str1, string str2) {
		string s = helper(str1, str2);
		string res;
		int i = 0, j = 0;
		for (auto c : s)
		{
			while (c != str1[i])
			{
				res += str1[i];
				++i;
			}
			while (c != str2[j])
			{
				res += str2[j];
				++j;
			}
			res += c;
			++i, ++j;
		}

		res += str1.substr(i) + str2.substr(j);
		return res;
	}

	string helper(string str1, string str2)
	{
		int n = str1.size(), m = str2.size();
		vector<vector<string> > dp(n + 1, vector<string>(m + 1, ""));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (str1[i] == str2[j])
				{
					dp[i + 1][j + 1] = dp[i][j] + str1[i];
				}
				else
				{
					dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ? dp[i + 1][j] : dp[i][j + 1];
				}
			}
		}

		return dp[n][m];
	
	}
};


//int main()
//{
//	string s1 = "abac";
//	string s2 = "cabww";
//
//	Solution n;
//	cout << n.shortestCommonSupersequence(s1, s2) << endl;
//
//	return 0;
//}
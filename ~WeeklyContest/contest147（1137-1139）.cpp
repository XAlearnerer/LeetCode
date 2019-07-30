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


class Solution1137 {
public:
	int tribonacci(int n) {
		if (n == 0) return 0;
		else if (n == 2 || n == 1) return 1;
		/*else return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);*/

		int a = 0, b = 1, c = 1, d = 2;
		for (int i = 1; i < n - 1; ++i)
		{
			d = a + b + c;
			a = b;
			b = c;
			c = d;
		}
		return d;

	}
};


///////////////////////////////////////////////////////////////////////////////



class Solution1138 {
public:
	string alphabetBoardPath(string target) {
		if (target.empty()) return "";
		string res;
		int prea = 0, preb = 0;

		for (auto i : target)
		{
			int gola = (i - 'a') / 5, golb = (i - 'a') % 5;
			while (1)
			{
				if (gola == prea && golb == preb) {
					res += '!';
					break;
				}
				while (gola < prea)
				{
					res += 'U'; --prea;
				}
				while (gola > prea)
				{
					if (gola == 5 && golb == 0 && prea ==4 && preb != 0) break;
					
					res += 'D'; ++prea;
				}
				while (golb < preb)
				{
					res += 'L'; --preb;
				}
				while (golb > preb)
				{
					res += 'R'; ++preb;
				}
			}

			prea = gola, preb = golb;
		}
		return res;

	}
};




///////////////////////////////////////////////////////////////////////////////



class Solution1139 {
public:
	int largest1BorderedSquare(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int n = grid.size(), m = grid[0].size();
		vector<vector<int> > hor(n, vector<int>(m, 0));
		vector<vector<int> > ver(n, vector<int>(m, 0));
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == 1)
				{
					//if (i > 0) hor[i][j] += hor[i - 1][j];
					hor[i][j] = (i == 0) ? 1 : hor[i - 1][j] + 1;
					ver[i][j] = (j == 0) ? 1 : ver[i][j - 1] + 1;
				}
			}
		}


		int res = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = m - 1; j >= 0; --j)
			{
				int small = min(hor[i][j], ver[i][j]);
				while (small > res)
				{
					if (ver[i - small + 1][j] >= small && hor[i][j - small + 1] >= small)
						res = small;
					--small;
				}
			}
		}
		return res*res;
	}
};



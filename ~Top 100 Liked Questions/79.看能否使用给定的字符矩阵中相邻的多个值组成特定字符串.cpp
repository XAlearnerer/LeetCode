#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
			
		int m = board.size(), n = board[0].size();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == word[0])
				{
					vector<vector<int>> vis(m, vector<int>(n, 0));
					if (helper(board, word, i, j, "", vis) ) return true;
				}
			}
		}
		return false;
	}

	bool helper(vector<vector<char>>& board, string word,int i,int j,string cur, vector<vector<int>>& vis)
	{
		int m = board.size(), n = board[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n) return false;
		if (vis[i][j] == 1) return false;
		int k = cur.size();
		if (board[i][j] != word[k]) return false;
		cur += board[i][j];
		if (cur == word) return true;

		vis[i][j] = 1;
		//if (i > 0)	return helper(board, word, i - 1, j, cur, vis);
		//if (i < m - 1) return helper(board, word, i + 1, j, cur, vis);
		//if (j > 0)	return helper(board, word, i, j - 1, cur, vis);
		//if (j < n - 1) return helper(board, word, i, j + 1, cur, vis);

		bool res = helper(board, word, i - 1, j, cur, vis) || helper(board, word, i + 1, j, cur, vis)
			|| helper(board, word, i, j - 1, cur, vis) || helper(board, word, i, j + 1, cur, vis);
		vis[i][j] = 0;

		return res;
	}

};



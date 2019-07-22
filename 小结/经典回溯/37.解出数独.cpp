#include<iostream>
#include<vector>

using namespace std;


// 对 box 中的值的判断。。。
//? board[i - i % 3 + k / 3][j - j % 3 + k % 3]

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		if (board.size() != 9 || board[0].size() != 9) return;
		helper(board, 0, 0);
	}

	bool helper(vector<vector<char>>& board,int i,int j)
	{
		if (i == 9) return true;
		if (j == 9) return helper(board, i + 1, 0);
		if (board[i][j] != '.') return helper(board, i, j + 1);

		for (char c = '1'; c <= '9'; ++c)
		{
			//board[i][j] = c;
			//if (check()) helper(board, i, j + 1);
			//board[i][j] = '.';

			if (check(board, i, j, c))
			{
				board[i][j] = c;
				if (helper(board, i, j + 1)) return true;
				board[i][j] = '.';
			}

		}
		return false;
	}

	bool check(vector<vector<char>>& board, int i, int j, char c)
	{
		for (int k = 0; k < 9; ++k)
		{
			if (board[i][k] == c) return false;
			if (board[k][j] == c) return false;
			
			if (board[i - i % 3 + k / 3][j - j % 3 + k % 3] == c) return false;

		}
		return true;
	}

};


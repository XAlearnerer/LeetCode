//
// Created by zhao on 18-10-24.
//

#include <iostream>
#include <vector>
using namespace std;

// 回溯法 
//
// Created by zhao on 18-10-24.
//

#include <iostream>
#include <vector>
using namespace std;

// 回溯法  
class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {
		if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
		//solveSudokuDFS(board, 0, 0);
		//solve(board, 0, 0);
		solveSudoku_2(board, 0, 0);
	}

	bool solveSudoku_2(vector<vector<char>> &board, int i, int j)
	{
		if (i == 9) return true;
		if (j == 9) return solveSudoku_2(board, i + 1, 0);
		if (board[i][j] != '.') return solveSudoku_2(board, i, j + 1);

		for (char c = '1'; c <= '9'; c++)
		{
			if (isValid(board, i, j))
			{
				board[i][j] = c;
				if (solveSudoku_2(board, i, j + 1)) return true;
				board[i][j] = '.';
			}
		}
		return false;
	}
	bool solve(vector<vector<char>> &board, int i, int j)
	{
		if (i == 9) return true;
		if (j == 9) return solve(board, i + 1, 0);
		if (board[i][j] != '.') return solve(board, i, j + 1);

		for (char k = '1'; k <= '9'; ++k)
		{
			if (isValid(board, i, j))
			{
				board[i][j] = k;
				if (solve(board, i, j + 1)) return true;
				board[i][j] = '.';
			}
		}
		return false;
	}
	bool solveSudokuDFS(vector<vector<char> > &board, int i, int j) {
		if (i == 9) return true;
		if (j >= 9) return solveSudokuDFS(board, i + 1, 0);
		if (board[i][j] == '.') {
			for (int k = 1; k <= 9; ++k) {
				board[i][j] = (char)(k + '0');
				if (isValid(board, i, j)) {
					if (solveSudokuDFS(board, i, j + 1)) return true;
				}
				board[i][j] = '.';
			}
		}
		else {
			return solveSudokuDFS(board, i, j + 1);
		}
		return false;
	}
	bool isValid(vector<vector<char> > &board, int i, int j) {
		for (int col = 0; col < 9; ++col) {
			if (col != j && board[i][j] == board[i][col]) return false;
		}
		for (int row = 0; row < 9; ++row) {
			if (row != i && board[i][j] == board[row][j]) return false;
		}
		for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row) {
			for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col) {
				if ((row != i || col != j) && board[i][j] == board[row][col]) return false;
			}
		}
		return true;
	}
};



class Solution2 {
public:
	void solveSudoku(vector<vector<char>>& board) {
		solveSudoku(board, 0, 0);
	}

	bool solveSudoku(vector<vector<char>> &board, int i, int j)
	{
		if (i == 9) return true;
		if (j == 9) return solveSudoku(board, i + 1, 0);
		if (board[i][j] != '.') return solveSudoku(board, i, j + 1);

		for (char c = '1'; c <= '9'; c++)
		{
			//if (check(board, i, j, c))
			//if(isValid(board, i, j))
			if (check_2(board, i, j, c))

			{
				board[i][j] = c;
				if (solveSudoku(board, i, j + 1)) return true;
				board[i][j] = '.';
			}
		}

		return false;
	}

	bool check(vector<vector<char>> &board, int i, int j, char val)
	{
		int row = i - i % 3, column = j - j % 3;
		for (int x = 0; x < 9; x++) if (board[x][j] == val) return false;
		for (int y = 0; y < 9; y++) if (board[i][y] == val) return false;
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++)
				if (board[row + x][column + y] == val) return false;
		return true;
	}

	bool isValid(vector<vector<char> > &board, int i, int j) {
		for (int col = 0; col < 9; ++col) {
			if (col != j && board[i][j] == board[i][col]) return false;
		}
		for (int row = 0; row < 9; ++row) {
			if (row != i && board[i][j] == board[row][j]) return false;
		}
		for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row) {
			for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col) {
				if ((row != i || col != j) && board[i][j] == board[row][col]) return false;
			}
		}
		return true;
	}

	bool check_2(vector<vector<char>>& board, int i, int j, char val) {

		for (int h = 0; h < 9; h++)
		{
			if (board[i][h] == val) return false; /* check row */
			if (board[h][j] == val) return false; /* check col */
			if (board[i - i % 3 + h / 3][j - j % 3 + h % 3] == val)return false; /* check cube */
		}

		return true;
	}

};

int  main()
{
	vector<vector<char>> board = {
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } };

	Solution2 n;
	n.solveSudoku(board);
	for (auto i : board)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}




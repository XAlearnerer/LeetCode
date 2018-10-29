//
// Created by zhao on 18-10-24.
//

#include <iostream>
#include <vector>
using namespace std;

// 回溯法  不会呀
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
		solveSudokuDFS(board, 0, 0);
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

	Solution n;
	n.solveSudoku(board);
	for (auto i : board)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}




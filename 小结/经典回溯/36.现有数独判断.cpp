#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int row[9][9] = { 0 };
		int col[9][9] = { 0 };
		int box[9][9] = { 0 };

		for (int i = 0; i != 9; ++i) {
			for (int j = 0; j != 9; ++j) {
				if (board[i][j] == '.') continue;
				int num = board[i][j] - '0' - 1;
				if (row[i][num]==1 || col[num][j]==1 || box[(i / 3) * 3 + j / 3][num]==1)
					return 0;
				row[i][num] = 1;
				col[num][j] = 1;
				box[(i / 3) * 3 + j / 3][num] = 1;
			}
		}
		return true;

	}
};


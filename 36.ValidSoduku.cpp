//
// Created by zhao on 18-10-24.
//
#include <vector>
using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
            bool row[9][9]={false};
            bool col[9][9]={false};
            bool box[9][9]={false};

            for(int i=0;i!=9;++i) {
                    for (int j = 0; j != 9; ++j) {
                            if(board[i][j]=='.')
                                    continue;
							int num = board[i][j] - '0' - 1;
                            if(row[i][num])
                                    return false;
							row[i][num] = true;
							if (col[num][j])
                                    return false;
							col[num][j] = true;
							if (box[(i / 3) * 3 + j / 3][num])
                                    return false;
							box[(i / 3) * 3 + j / 3][num] = true;
                    }
            }
            return true;

    }
};

class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (size_t i = 0; i < 9; i += 3) {
            for (size_t j = 0; j < 9; j += 3) {
                vector<bool> m(9);
                for (size_t I = i; I < i+3; ++I) {
                    for (size_t J = j; J < j+3; ++J) {
                        char ch = board[I][J];
                        if (ch != '.') {
                            if (m[ch]) {
                                return false;
                            }
                            else {
                                m[ch] = true;
                            }
                        }
                    }
                }
            }
        }
        for (size_t i = 0; i < 9; ++i) {
            vector<bool> m(9), m2(9);
            for (size_t j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch != '.') {
                    if (m[ch]) {
                        return false;
                    }
                    else {
                        m[ch] = true;
                    }
                }
                char ch2 = board[j][i];
                if (ch2 != '.') {
                    if (m2[ch2]) {
                        return false;
                    }
                    else {
                        m2[ch2] = true;
                    }
                }
            }
        }
        return true;
    }
};

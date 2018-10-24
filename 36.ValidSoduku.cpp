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
                            int num=board[i][j]-'0'-1;
                            if(row[i][num])
                                    return false;
                            row[i][num]=true;
                            if(col[num][j])
                                    return false;
                            col[num][j]=true;
                            if(box[(i/3)*3+j/3][num])
                                    return false;
                            box[(i/3)*3+j/3][num]=true;
                    }
            }
            return true;

    }
};
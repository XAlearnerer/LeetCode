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
		return getMaxSize(grid);
	}

	//根据m矩阵，设置right与down矩阵，right[i][j]表示m[i][j]的右边有多少个连续的1，包括自身
	//down[i][j]表示m[i][j]的下边有多少个连续的1，包括自身
	void setRightAndDown(vector<vector<int>>& m, vector<vector<int>>& right, vector<vector<int>>& down) {
		int rowNum = m.size();
		int colNum = m[0].size();
		//初始化右下角位置
		right[rowNum - 1][colNum - 1] = m[rowNum - 1][colNum - 1];
		down[rowNum - 1][colNum - 1] = m[rowNum - 1][colNum - 1];
		//初始化最后一行
		for (int col = colNum - 2; col >= 0; col--) {
			if (m[rowNum - 1][col] == 1) {
				right[rowNum - 1][col] = right[rowNum - 1][col + 1] + 1;
				down[rowNum - 1][col] = 1;
			}
		}
		//初始化最后一列
		for (int row = rowNum - 2; row >= 0; row--) {
			if (m[row][colNum - 1] == 1) {
				right[row][colNum - 1] = 1;
				down[row][colNum - 1] = down[row + 1][colNum - 1] + 1;
			}
		}
		//其他位置，从右向左，从下到上设置值
		for (int row = rowNum - 2; row >= 0; row--) {
			for (int col = colNum - 2; col >= 0; col--) {
				if (m[row][col] == 1) {
					right[row][col] = right[row][col + 1] + 1;
					down[row][col] = down[row + 1][col] + 1;
				}
			}
		}
	}

	int getMaxSize(vector<vector<int>>& m) {
		int rows = m.size();
		int cols = m[0].size();
		vector<vector<int>> right(rows, vector<int>(cols, 0));
		vector<vector<int>> down(rows, vector<int>(cols, 0));
		setRightAndDown(m, right, down);

		for (int length = min(m.size(), m[0].size()); length >= 1; length--) {
			//对于每个边长，看是否存在以该值作为边长的矩阵，满足四周全为1
			//因为要找最大边长，所以从大到小找
			if (hasSizeOfBorder(length, right, down)) {
				return length;
			}
		}
		return 0;
	}

	//该函数实现传入一个边长值，根据right与down矩阵，判断是否存在正方形满足四周全为1
	bool hasSizeOfBorder(int length, vector<vector<int>>& right, vector<vector<int>>& down) {
		for (int row = 0; row + length - 1 <= right.size() - 1; row++) {
			for (int col = 0; col + length - 1 <= right[0].size() - 1; col++) {
				//row,col代表左上方的位置，要求左上方处下边最少有连续的length个1，右边最少有连续的length个1
				//[row + length - 1][col]代表左下角，要求该点右边最少有连续的length个1
				//[row][col + length - 1]代表右上角，要求该点下边最少有连续的length个1
				//这样便确立了四个边
				if (right[row][col] >= length && down[row][col] >= length
					&& right[row + length - 1][col] >= length
					&& down[row][col + length - 1] >= length) {
					return true;
				}
			}
		}
		return false;
	}



};


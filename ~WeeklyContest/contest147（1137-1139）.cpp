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

	//����m��������right��down����right[i][j]��ʾm[i][j]���ұ��ж��ٸ�������1����������
	//down[i][j]��ʾm[i][j]���±��ж��ٸ�������1����������
	void setRightAndDown(vector<vector<int>>& m, vector<vector<int>>& right, vector<vector<int>>& down) {
		int rowNum = m.size();
		int colNum = m[0].size();
		//��ʼ�����½�λ��
		right[rowNum - 1][colNum - 1] = m[rowNum - 1][colNum - 1];
		down[rowNum - 1][colNum - 1] = m[rowNum - 1][colNum - 1];
		//��ʼ�����һ��
		for (int col = colNum - 2; col >= 0; col--) {
			if (m[rowNum - 1][col] == 1) {
				right[rowNum - 1][col] = right[rowNum - 1][col + 1] + 1;
				down[rowNum - 1][col] = 1;
			}
		}
		//��ʼ�����һ��
		for (int row = rowNum - 2; row >= 0; row--) {
			if (m[row][colNum - 1] == 1) {
				right[row][colNum - 1] = 1;
				down[row][colNum - 1] = down[row + 1][colNum - 1] + 1;
			}
		}
		//����λ�ã��������󣬴��µ�������ֵ
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
			//����ÿ���߳������Ƿ�����Ը�ֵ��Ϊ�߳��ľ�����������ȫΪ1
			//��ΪҪ�����߳������ԴӴ�С��
			if (hasSizeOfBorder(length, right, down)) {
				return length;
			}
		}
		return 0;
	}

	//�ú���ʵ�ִ���һ���߳�ֵ������right��down�����ж��Ƿ������������������ȫΪ1
	bool hasSizeOfBorder(int length, vector<vector<int>>& right, vector<vector<int>>& down) {
		for (int row = 0; row + length - 1 <= right.size() - 1; row++) {
			for (int col = 0; col + length - 1 <= right[0].size() - 1; col++) {
				//row,col�������Ϸ���λ�ã�Ҫ�����Ϸ����±�������������length��1���ұ�������������length��1
				//[row + length - 1][col]�������½ǣ�Ҫ��õ��ұ�������������length��1
				//[row][col + length - 1]�������Ͻǣ�Ҫ��õ��±�������������length��1
				//������ȷ�����ĸ���
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


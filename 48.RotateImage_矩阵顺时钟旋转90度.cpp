#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int bR = 0;
		int eR = matrix.size() - 1;
		while (bR < eR)
		{
			circleRotate(matrix, bR, bR, eR, eR);
			bR++;
			eR--;
		}
	}

	void circleRotate(vector<vector<int>>& matrix, int bR, int bC, int eR, int eC)
	{
		int times = eR - bR;
		for (int i = 0; i != times; ++i)
		{
			int tmp = matrix[bR][bC + i];
			matrix[bR][bC + i] = matrix[eR - i][bC];
			matrix[eR - i][bC] = matrix[eR][eC - i];
			matrix[eR][eC - i] = matrix[bR + i][eC];
			matrix[bR + i][eC] = tmp;
		}
	
	}
};


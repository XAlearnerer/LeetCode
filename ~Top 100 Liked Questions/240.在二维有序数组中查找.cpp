#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int n = matrix.size(), m = matrix[0].size();
		int i = n - 1, j = 0;
		while (i >= 0 && j < m)
		{
			if (matrix[i][j] == target) return true;
			else if (matrix[i][j] > target) --i;
			else ++j;
		}
		return false;
	}
};
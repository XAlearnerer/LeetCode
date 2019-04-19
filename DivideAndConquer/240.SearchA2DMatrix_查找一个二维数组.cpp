#include<iostream>
#include<vector>

using namespace std;


	     
	//   [1, 4, 7, 11, 15],
	//   [2, 5, 8, 12, 19],
	//   [3, 6, 9, 16, 22],
	//   [10, 13, 14, 17, 24],
	//   [18, 21, 23, 26, 30]
	     

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int m = matrix.size(), n = matrix[0].size();
		int i = 0, j = n - 1;
		while (i < m && j >= 0)
		{
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] < target)
				++i;
			else
				--j;
		}
		return false;
	}
};

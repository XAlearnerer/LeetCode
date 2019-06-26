#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty()) return;
		int n = matrix.size();
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
				swap(matrix[i][j], matrix[j][i]);

			reverse(matrix[i].begin(), matrix[i].end());
		}
	}
};


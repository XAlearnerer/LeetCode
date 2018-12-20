#include<iostream>
#include<vector>
using namespace std;

class Solution { // 这个函数不知道怎么救了
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return {};
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> v;

		int turnrow = m - 1;
		int turncol = n - 1;
		while (turnrow >= 0 && turncol >= 0)
		{
			int i = n - 1 - turncol;
			for (; i <= turncol; ++i)
			{
				v.push_back(matrix[m - 1 - turnrow][i]);
			}
			//v.push_back(99);

			int j = m - turnrow;
			for (; j <= turnrow; ++j)
			{
				v.push_back(matrix[j][turncol]);
			}
			//v.push_back(99);

			int k = turncol - 1;
			for (; k >= n - 1 - turncol && turnrow >= 1; --k)
			{
				v.push_back(matrix[turnrow][k]);
			}
			//v.push_back(99);

			int l = turnrow - 1;
			for (; l > m - 1 - turnrow && turncol >= 1; --l)
			{
				v.push_back(matrix[l][n - 1 - turncol]);
			}
			--turnrow;
			--turncol;
		}

		return v;
	}
};

class Solution2 {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty()) return {};
		int m = matrix.size(), n = matrix[0].size();
		vector<int> spiral(m * n);
		int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
		while (true) {
			// up
			for (int col = l; col <= r; col++) spiral[k++] = matrix[u][col];
			if (++u > d) break;
			// right
			for (int row = u; row <= d; row++) spiral[k++] = matrix[row][r];
			if (--r < l) break;
			// down
			for (int col = r; col >= l; col--) spiral[k++] = matrix[d][col];
			if (--d < u) break;
			// left
			for (int row = d; row >= u; row--) spiral[k++] = matrix[row][l];
			if (++l > r) break;
		}
		return spiral;
	}
};

int main1601()
{
	vector<vector<int>> vv = { {1, 2, 3, 4},{5, 6, 7, 8},{9,10,11,12} };
	//vector<vector<int>> vv = { { 1} };
	//vector<vector<int>> vv = { {3} ,{2} };
	//vector<vector<int>> vv = { { 1,2 } ,{ 3,4 } };
	Solution n;
	vector<int > v = n.spiralOrder(vv);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	return 0;
}



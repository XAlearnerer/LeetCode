#include<iostream>
#include<vector>
using namespace std;

class Solution {
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
			int j = m - turnrow;
			for (; j <= turnrow; ++j)
			{
				v.push_back(matrix[j][turncol]);
			}
			int k = turncol - 1;
			for (; k > n - 1 - turncol; --k)
			{
				v.push_back(matrix[turnrow][k]);
			}
			int l = turnrow;
			for (; l > m - 1 - turnrow; --l)
			{
				v.push_back(matrix[l][n - 1 - turncol]);
			}
			--turnrow;
			--turncol;
		}

		return v;
	}
};


int main()
{
	//vector<vector<int>> vv = { {1, 2, 3, 4},{5, 6, 7, 8},{9,10,11,12} };
	//vector<vector<int>> vv = { { 1} };
	vector<vector<int>> vv = { { 3} ,{2} };
	Solution n;
	vector<int > v = n.spiralOrder(vv);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	return 0;
}
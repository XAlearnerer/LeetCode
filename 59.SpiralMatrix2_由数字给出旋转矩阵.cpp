#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int u = 0, d = n - 1, l = 0, r = n - 1;
		int k = 1;
		//vector<int> v;
		vector<vector<int>> vv;
		for (int i = 0; i != n; ++i)
		{
			vector<int> v(n, 0);
			vv.push_back(v);
		}
		while (1)
		{
			for (int col = l; col <= r; ++col)
				vv[u][col] = k++;
			if (++u > d) break;
			for (int row = u; row <= d; ++row)
				vv[row][r] = k++;
			if (--r < l) break;
			for (int col = r; col >= l; --col)
				vv[d][col] = k++;
			if (--d < u) break;
			for (int row = d; row >= u; --row)
				vv[row][l] = k++;
			if (++l > r) break;
		}


		//vector<vector<int>> vv;
		//int i = 0, j = 0;
		//while (j != n)
		//{
		//	vector<int> v1(v.begin() + i, v.begin() + i + n);
		//	vv.push_back(v1);
		//	i += n;
		//	++j;
		//}

		return vv;
	}
};

int main1047()
{
	Solution n;
	vector<vector<int> >vv = n.generateMatrix(4);
	for (auto i : vv) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}
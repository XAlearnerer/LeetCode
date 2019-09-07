//
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int helper(vector<vector<char>>& v,int x,int y)
//{
//	int row = v.size();
//	int col = v[0].size();
//	int res = 0;
//	char sym = v[x][y];
//	bool flag1 = false;;
//	bool flag2 = false;
//
//	int a = x, b = x;
//	int cur = 0;
//	while (a > 0 && sym == v[a][y])
//	{
//		++cur;
//		--a;
//	}
//	while (b < col - 1 && sym == v[b][y])
//	{
//		++cur;
//		++b;
//	}
//	if (cur >= 3)
//	{
//		res += cur;
//		flag1 = true;
//	}
//
//	a = y, b = y;
//	cur = 0;
//	while (a > 0 && sym == v[x][a])
//	{
//		++cur;
//		--a;
//	}
//	while (b < row - 1 && sym == v[x][b])
//	{
//		++cur;
//		++b;
//	}
//	if (cur >= 3)
//	{
//		res += cur;
//		flag2 = true;
//	}
//	
//	if (flag1 && flag2) --res;
//	return res;
//}
//
//
////4 4
////HFCE
////GCAC
////GFAD
////DCBA
////3 2 3 3
//
//
//int main()
//{
//	int col, row;
//	//cin >> row >> col;
//
//	row = 4, col = 4;
//	vector<vector<char>> v = {
//		{'H','F','C','E'},
//		{'G','C','A','C'},
//		{'G','F','A','D'},
//		{'D','C','B','A'} };
//	//vector<vector<char>> v(row, vector<char>(col));
//	//for (int i = 0; i<row; ++i)
//	//{
//	//	for (int j = 0; j<col; ++j)
//	//	{
//	//		cin >> v[i][j];
//	//	}
//	//}
//
//
//
//	int x1, y1, x2, y2;
//	//cin >> x1 >> y1 >> x2 >> y2;
//
//	x1 = 3, y1 = 2, x2 = 3, y2 = 3;
//
//	swap(v[x1][y1], v[x2][y2]);
//
//	for (auto i : v)
//	{
//		for (auto j : i)
//			cout << j << " ";
//		cout << endl;
//	}
//
//	int a = helper(v, x1, y1);
//	int b = helper(v, x2, y2);
//
//	cout << a + b << endl;
//	//cout << helper(v, x1, y1) + helper(v, x2, y2) << endl;
//
//	return 0;
//}



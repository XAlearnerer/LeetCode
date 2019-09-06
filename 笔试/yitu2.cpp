//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//
//int zeroline = 0;
//
//void helper(vector<vector<int>>& star, int a, int b, int& res, int& value,
//	vector<vector<int>>& vis)
//{
//	int n = star.size();
//	if (a < 0 || a >= n || b < 0 || b >= n) return;
//	if (star[a][b] != value) return;
//	if (vis[a][b] == 1) return;
//
//	if (res >= 1)
//	{
//		star[a][b] = 0;
//	}
//
//	++res;
//	vis[a][b] = 1;
//
//	helper(star, a + 1, b, res, value, vis);
//	helper(star, a - 1, b, res, value, vis);
//	helper(star, a, b + 1, res, value, vis);
//	helper(star, a, b - 1, res, value, vis);
//}
//
//bool checkline(vector<vector<int>>& star,vector<int>& line)
//{
//	int n = star.size();
//	bool f = true;
//	for (int j = 0; j < n; ++j)
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			if (star[i][j] != 0)
//			{
//				f = false;
//				break;
//			}
//		}
//
//		if (f) line.push_back(j);
//		f = true;
//	}
//
//	if (line.empty()) return false;
//	else return true;
//}
//
//void eline(vector<vector<int>>& star)
//{
//	vector<int> line;
//	if (!checkline(star, line)) return;
//	int n = star.size();
//
//	for (int i = 0; i < line.size(); ++i)
//	{
//		int t = line[i];
//		if (t == n - 1) continue;
//		for (int k = t; k < n - 1; ++k)
//		{
//			for (int p = 0; p < n; ++p)
//			{
//				star[p][k] = star[p][k + 1];
//			}
//
//			//for (auto i : star)
//			//{
//			//	for (auto j : i)
//			//		cout << j << " ";
//			//	cout << endl;
//			//}
//			//cout << endl;
//
//		}
//
//		++zeroline;
//
//		for (int r = 0; r < n; ++r)
//			star[r][n - zeroline] = 0;
//
//	}
//}
//
//
//void down(vector<vector<int>>& star)
//{
//	int n = star.size();
//	vector<int> t;
//	for (int j = 0; j < n; ++j)
//	{
//		for (int i = n - 1; i >= 0; --i)
//		{
//			if (star[i][j] == 0)
//			{
//
//			}
//		}
//
//	}
//	
//
//}
//
//
//void erase(vector<vector<int>>& star, int x, int y)
//{
//	int n = star.size();
//	if (star[x][y] == 0)
//	{
//		cout << "empty!" << endl;
//		return;
//	}
//
//	vector<vector<int>> vis(n, vector<int>(n, 0));
//
//	int res = 0;
//	helper(star, x, y, res, star[x][y], vis);
//	if (res == 1) cout << "only one!" << endl;
//	else
//	{
//		star[x][y] = 0;
//		cout << res << endl;
//		
//		eline(star);
//		down(star);
//	}
//
//
//}
//
//
//
//int main()
//{
//	int n, m;
//	//cin >> n >> m;
//	n = 5, m = 1;
//	/*vector<vector<int> > star(n, vector<int>(n, 0));
//	for (int i = 0; i<n; ++i)
//	{
//		for (int j = 0; j<n; ++j)
//			cin >> star[i][j];
//	}*/
//	vector<vector<int> > star = {
//		{1, 2, 1, 4 ,1},
//		{1, 1, 1, 1, 3},
//		{2 ,4 ,1 ,2 ,3},
//		{2 ,5, 1 ,3 ,2},
//		{5, 2, 1, 5, 5} };
//
//
//
//	for (int k = 0; k < m; ++k)
//	{
//		int _x, _y;
//		//cin >> _x >> _y;
//		_x = 1, _y = 3;
//		int x = n - _x, y = _y - 1;
//		erase(star, x, y);
//
//
//		for (auto i : star)
//		{
//			for (auto j : i)
//				cout << j << " ";
//			cout << endl;
//		}
//
//	}
//
//	return 0;
//}

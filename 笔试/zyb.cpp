//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	int m, n;
//
//	cin >> m >> n;
//	vector<vector<int>> v(m, vector<int>(n, 0));
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//			cin >> v[i][j];
//	}
//
//	//m = 2, n = 3;
//	//vector<vector<int>> v = { {9,8,6},{2,3,7} };
//
//
//
//	vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
//	dp[0][0] = v[0][0];
//	for (int i = 1; i < m; ++i) dp[i][0] = v[i][0] + dp[i - 1][0];
//	for (int j = 1; j < n; ++j) dp[0][j] = v[0][j] + dp[0][j - 1];
//
//	for (int i = 1; i < m; ++i)
//	{
//		for (int j = 1; j < n; ++j)
//		{
//			dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1])) + v[i][j];
//		}
//	}
//
//	//for (auto i : dp)
//	//{
//	//	for (auto j : i)
//	//		cout << j << " ";
//	//	cout << endl;
//	//}
//
//	cout << dp[m - 1][n - 1] << endl;
//
//	return 0;
//}